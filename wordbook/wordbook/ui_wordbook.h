/********************************************************************************
** Form generated from reading UI file 'wordbook.ui'
**
** Created: Sun Nov 4 11:39:16 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDBOOK_H
#define UI_WORDBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordBook
{
public:
    QAction *actionExport;
    QAction *actionImport;
    QAction *actionQuit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *WordBook)
    {
        if (WordBook->objectName().isEmpty())
            WordBook->setObjectName(QString::fromUtf8("WordBook"));
        WordBook->resize(663, 328);
        actionExport = new QAction(WordBook);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionImport = new QAction(WordBook);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionQuit = new QAction(WordBook);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(WordBook);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(448, 293));
        centralWidget->setAutoFillBackground(true);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        gridLayout = new QGridLayout(tableView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        horizontalLayout->addWidget(tableView);

        WordBook->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WordBook);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WordBook->setStatusBar(statusBar);
        toolBar = new QToolBar(WordBook);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        WordBook->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(WordBook);
        QObject::connect(actionQuit, SIGNAL(triggered()), WordBook, SLOT(close()));

        QMetaObject::connectSlotsByName(WordBook);
    } // setupUi

    void retranslateUi(QMainWindow *WordBook)
    {
        WordBook->setWindowTitle(QApplication::translate("WordBook", "WordBook", 0, QApplication::UnicodeUTF8));
        actionExport->setText(QApplication::translate("WordBook", "Export", 0, QApplication::UnicodeUTF8));
        actionImport->setText(QApplication::translate("WordBook", "Import", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("WordBook", "Quit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("WordBook", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WordBook: public Ui_WordBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDBOOK_H
