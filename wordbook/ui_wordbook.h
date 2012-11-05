/********************************************************************************
** Form generated from reading UI file 'wordbook.ui'
**
** Created: Mon Nov 5 21:36:21 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "wordbookdock.h"

QT_BEGIN_NAMESPACE

class Ui_WordBook
{
public:
    QAction *actionExport;
    QAction *actionImport;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    wordbookDock *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QMainWindow *WordBook)
    {
        if (WordBook->objectName().isEmpty())
            WordBook->setObjectName(QString::fromUtf8("WordBook"));
        WordBook->resize(749, 478);
        WordBook->setContextMenuPolicy(Qt::DefaultContextMenu);
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
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WordBook->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WordBook);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WordBook->setStatusBar(statusBar);
        toolBar = new QToolBar(WordBook);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        WordBook->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new wordbookDock(WordBook);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(300, 124));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dockWidget->setWidget(dockWidgetContents);
        WordBook->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

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
        dockWidget->setWindowTitle(QApplication::translate("WordBook", "wordbook", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WordBook: public Ui_WordBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDBOOK_H
