#include "wordbookdock.h"
#include "ui_wordbookdock.h"
#include "database.h"

#include <QSqlTableModel>
#include <QCompleter>
#include <QShortcut>
#include <QDebug>
#include <QMenu>
#include <QSqlRecord>
#include <QKeyEvent>


wordbookDock::wordbookDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::wordbookDock)
{
    ui->setupUi(this);
    /// hide the title bar
    QWidget * titleBar = new QWidget(this);
    setTitleBarWidget(titleBar);

    /// no edit is possible
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->tableView->setSortingEnabled(true);
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setResizeMode(QHeaderView::Stretch);

    dbInterface = new DB(this);
    model = new QSqlTableModel(this);
    dbInterface->fillModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->sortByColumn(0, Qt::DescendingOrder);
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(displayMenu(QPoint)));
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(selectionChanged(QModelIndex)));


    ui->searchBox->setPlaceholderText("search...");
    QCompleter *completer = new QCompleter(model, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionColumn(1);
    ui->searchBox->setCompleter(completer);
    connect(ui->searchBox, SIGNAL(returnPressed()), this, SLOT(showSearchResult()));
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Shift+F"), this);
    //ui->searchBox->hide();
    connect(shortcut, SIGNAL(activated()), ui->searchBox, SLOT(show()));
    connect(shortcut, SIGNAL(activated()), ui->searchBox, SLOT(setFocus()));

    updateStatusLine();

    /*
    LineEdit * searchBox = new LineEdit(this);
    searchBox->setPlaceholderText("search...");
    QCompleter *completer = new QCompleter(model, this);
    completer->setCompletionColumn(1);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    searchBox->setCompleter(completer);
    connect(searchBox, SIGNAL(returnPressed()), this, SLOT(showSearchResult()));
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Shift+F"), this);
    connect(shortcut, SIGNAL(activated()), searchBox, SLOT(setFocus()));
    ui->verticalLayout->insertWidget(0,searchBox);
    */



}

wordbookDock::~wordbookDock()
{
    delete ui;
}

void wordbookDock::activeWordBook()
{
    //activateWindow();
    raise();
    //ui->searchBox->setFocus();
}

bool wordbookDock::closeSearch()
{
    if(ui->searchBox->isVisible())
    {
        ui->searchBox->hide();
        return true;
    }
    return false;
}

void wordbookDock::updateStatusLine()
{
    ui->statusLine->setText(QString("Total %1 words.").arg(model->rowCount()));
}

void wordbookDock::displayMenu(const QPoint &pos)
{

    QTableView *table = ui->tableView;
    QModelIndexList indexList = table->selectionModel()->selectedRows();
    int size = indexList.size();
    if(size != 0)
    {
        qSort(indexList);
        foreach(QModelIndex index, indexList)
            qDebug() << index.row();

        QMenu menu(this);
        QAction *remove = new QAction(this);

        if(size > 1)
            remove->setText(QString("remove %1 items").arg(size));
        else
            remove->setText(QString("remove"));

        menu.addAction(remove);
        QAction *a = menu.exec(table->viewport()->mapToGlobal(pos));
        if (a == remove)
        {
            int i = 0;
            foreach(QModelIndex index, indexList)
            {
                /*

                QAbstractItemDelegate *delegate = ui->tableView->itemDelegateForRow(index.row() -i);
                QPropertyAnimation animation(delegate, "height", this);
                animation.setDuration(3000);
                //animation.setStartValue(QRect(0, 0, 100, 30));
                animation.setEndValue(0;
                animation.setEasingCurve(QEasingCurve::OutBounce);
                animation.start();
                */

                model->removeRow(index.row() - i++ );
                model->submitAll();
                updateStatusLine();
            }

        }
    }
}

void wordbookDock::showSearchResult()
{
    QString text = ui->searchBox->text();
    if(text.isEmpty())
    {
        for(int row = 0; row < model->rowCount(); ++row )
            ui->tableView->setRowHidden(row, false);
        return;
    }

    //qDebug() << "search with keyword " << text;
    QModelIndexList indexList = model->match(model->index(0,1), Qt::DisplayRole, text, -1, Qt::MatchContains);

    for(int row = 0; row < model->rowCount(); ++row )
        ui->tableView->setRowHidden(row, true);

    foreach(QModelIndex index, indexList)
    {
        ui->tableView->setRowHidden(index.row(), false);
        //qDebug() << index.row();
    }
}

void wordbookDock::selectionChanged(const QModelIndex &index)
{
    //qDebug() << index.row();
    static QString preWord = "";
    QModelIndex tmp = model->index(index.row(), 1);
    QString word = tmp.data(Qt::DisplayRole).toString();

    if(word != preWord)
    {
        emit translate(word);
        preWord = word;
    }


}
void wordbookDock::toggleVisibility(bool checked)
{
    //qDebug() << "toggle visibility";
    if(checked) show();
    else hide();
}

bool wordbookDock::removeRecord(const QString &word)
{
    QModelIndexList indexList = model->match(model->index(0,1), Qt::DisplayRole, word, -1, Qt::MatchContains);
    if(indexList.count() == 1)
    {
        model->removeRow(indexList.first().row());
        model->submitAll();
        return true;
    }
    return false;
}

bool wordbookDock::addRecord(const QString &word)
{
    QSqlRecord tmp(model->record());
    if(hasRecord(word))
        return true;

    dbInterface->generateRecord(tmp, word);
    bool re1 = model->insertRecord(model->rowCount(), tmp);
    bool re2 = model->submitAll();
    updateStatusLine();

    return (re1 && re2);
}

const bool &wordbookDock::hasRecord(const QString &word) const
{
    QModelIndexList indexList = model->match(model->index(0,1), Qt::DisplayRole, word, -1, Qt::MatchContains);
    if(indexList.count() >= 1)
        return true;
    else return false;
}

bool wordbookDock::hasRecord(const QString &word)
{
    QModelIndexList indexList = model->match(model->index(0,1), Qt::DisplayRole, word, -1, Qt::MatchContains);
    if(indexList.count() >= 1)
        return true;
    else return false;
}

/// @todo, add the db import and export support
bool wordbookDock::importDB(const QString &file)
{


}

bool wordbookDock::exportDB(const QString &file)
{


}
