/********************************************************************************
** Form generated from reading UI file 'wordbookdock.ui'
**
** Created: Mon Nov 5 11:21:05 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDBOOKDOCK_H
#define UI_WORDBOOKDOCK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wordbookDock
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QDockWidget *wordbookDock)
    {
        if (wordbookDock->objectName().isEmpty())
            wordbookDock->setObjectName(QString::fromUtf8("wordbookDock"));
        wordbookDock->resize(400, 300);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(dockWidgetContents);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        wordbookDock->setWidget(dockWidgetContents);

        retranslateUi(wordbookDock);

        QMetaObject::connectSlotsByName(wordbookDock);
    } // setupUi

    void retranslateUi(QDockWidget *wordbookDock)
    {
        wordbookDock->setWindowTitle(QApplication::translate("wordbookDock", "WordBook", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wordbookDock: public Ui_wordbookDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDBOOKDOCK_H
