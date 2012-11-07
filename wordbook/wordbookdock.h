#ifndef WORDBOOKDOCK_H
#define WORDBOOKDOCK_H

#include <QDockWidget>
#include <QString>

namespace Ui {
class wordbookDock;
}

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
    bool removeRecord(const QString &word);
    const bool &hasRecord(const QString &word) const;
    bool hasRecord(const QString &word) ;
    bool closeSearch();

private:
    Ui::wordbookDock *ui;
    QSqlTableModel *model;
    DB *dbInterface;
    QString preWord;

signals:
    void translate(const QString &word);

private slots:
    void showSearchResult();
    void displayMenu(const QPoint &pos);
    void selectionChanged(const QModelIndex & index);
    void updateStatusLine();

public slots:
    void toggleVisibility();
    void activeWordBook();

};

#endif // WORDBOOKDOCK_H
