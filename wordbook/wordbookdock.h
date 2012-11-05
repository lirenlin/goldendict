#ifndef WORDBOOKDOCK_H
#define WORDBOOKDOCK_H

#include <QDockWidget>
#include <QString>

namespace Ui {
class wordbookDock;
}

class LineEdit;
class QSqlTableModel;
class DB;
class QModelIndex;

class wordbookDock : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit wordbookDock(QWidget *parent = 0);
    ~wordbookDock();
    bool addRecord(const QString &word);

private:
    Ui::wordbookDock *ui;
    LineEdit * searchBox;
    QSqlTableModel *model;
    DB *dbInterface;
    QString preWord;

signals:
    void translate(const QString &word);

private slots:
    void showSearchResult();
    void displayMenu(const QPoint &pos);
    void selectionChanged(const QModelIndex & index);

public slots:
    void toggleVisibility();

};

#endif // WORDBOOKDOCK_H