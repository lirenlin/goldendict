#include "DBInterface.h"

#include <QSqlQueryModel>

///change those if the interface is changed
const QList<QString> DBInterface::COLUMN_NAMES =
    QList<QString>() << "Name" << "Mean" << "Date"; 

const QString DBInterface::TABLE = QString("word");

const QString DBInterface::SQL_SELECT = 
    QString("SELECT * FROM %1").arg(DBInterface::TABLE);

    const QString DBInterface::DB_NAME = QString("lirenlin.db.sqlite");

DBInterface::DBInterface()
{
    model = new QSqlQueryModel;
    model->setQuery(SQL_SELECT);
    int index = 0;
    foreach(QString role, COLUMN_NAMES)
        model->setHeaderData(index++, Qt::Horizontal, role);

}
DBInterface::~DBInterface()
{
    delete model;
}

QSqlQueryModel * DBInterface::getModel() const
{
    return model;
}


