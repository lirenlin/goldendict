#ifndef DBINTERFACE_H
#define DBINTERFACE_H
#include <QString>
#include <QList>


class QSqlQueryModel;

class DBInterface {
public:
    DBInterface();
    virtual ~DBInterface();

    QSqlQueryModel * getModel() const;

    static const QList<QString> COLUMN_NAMES;
    static const QString SQL_SELECT;
    static const QString TABLE;
    static const QString DB_NAME;


private:
    /* data */
    QSqlQueryModel *model;
};



#endif /* end of include guard: DBINTERFACE_H */
