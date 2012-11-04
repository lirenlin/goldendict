#include "wordbook.h"
#include "ui_wordbook.h"
#include "database.h"

#include <QKeySequence>
#include <QDebug>
#include <QLineEdit>
#include <QSplitter>
#include <QSqlTableModel>

WordBook::WordBook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordBook)
{
    ui->setupUi(this);

    /// set the horizontal header auto resize when change window size
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setResizeMode(QHeaderView::Stretch);

    /// setup the toolbar
    setupToolBar();

    dbInterface = new DB(this);
    ui->tableView->setModel(dbInterface->getModel());
    //ui->tableView->setColumnHidden(3, true);

}

WordBook::~WordBook()
{
    delete ui;
}

void WordBook::setupToolBar()
{
    QToolBar *toolBar = ui->toolBar;

    QAction * exportAct = new QAction(QIcon(""), tr("&Export"), this);
    exportAct->setShortcuts(QKeySequence::Open);
    exportAct->setStatusTip(tr("export database"));
    connect(exportAct, SIGNAL(triggered()), this, SLOT(exportDB()));

    QAction * importAct = new QAction(QIcon(""), tr("&Import"), this);
    importAct->setShortcuts(QKeySequence::Open);
    importAct->setStatusTip(tr("import database"));
    connect(importAct, SIGNAL(triggered()), this, SLOT(importDB()));

    toolBar->addAction(exportAct);
    toolBar->addAction(importAct);

    toolBar->addSeparator();

    searchBox = new QLineEdit(this);
    searchBox->setPlaceholderText("search...");
    connect(searchBox, SIGNAL(returnPressed()), this, SLOT(showSearchResult()));

    toolBar->addWidget(searchBox);

    QSplitter *splitter = new QSplitter(this);
    toolBar->addWidget(splitter);

}

void WordBook::importDB()
{
    qDebug() << "import DB command received";
}
void WordBook::exportDB()
{
    qDebug() << "export DB command received";
}

void WordBook::showSearchResult()
{
    QString text = searchBox->text();
    if(text.isEmpty()) return;

    qDebug() << "search with keyword " << text;
}
