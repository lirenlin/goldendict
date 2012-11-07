/********************************************************************************
** Form generated from reading UI file 'wordbookdock.ui'
**
** Created: Wed Nov 7 16:23:20 2012
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
#include <QtGui/QLabel>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <lineedit.h>

QT_BEGIN_NAMESPACE

class Ui_wordbookDock
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    LineEdit *searchBox;
    QTableView *tableView;
    QLabel *statusLine;

    void setupUi(QDockWidget *wordbookDock)
    {
        if (wordbookDock->objectName().isEmpty())
            wordbookDock->setObjectName(QString::fromUtf8("wordbookDock"));
        wordbookDock->resize(400, 300);
        wordbookDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        wordbookDock->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchBox = new LineEdit(dockWidgetContents);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));

        verticalLayout->addWidget(searchBox);

        tableView = new QTableView(dockWidgetContents);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableView);

        statusLine = new QLabel(dockWidgetContents);
        statusLine->setObjectName(QString::fromUtf8("statusLine"));

        verticalLayout->addWidget(statusLine);

        wordbookDock->setWidget(dockWidgetContents);

        retranslateUi(wordbookDock);

        QMetaObject::connectSlotsByName(wordbookDock);
    } // setupUi

    void retranslateUi(QDockWidget *wordbookDock)
    {
        wordbookDock->setWindowTitle(QApplication::translate("wordbookDock", "WordBook", 0, QApplication::UnicodeUTF8));
        statusLine->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class wordbookDock: public Ui_wordbookDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDBOOKDOCK_H
