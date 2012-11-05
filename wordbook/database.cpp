#include "database.h"
#include "config.hh"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDate>
#include <QDebug>
#include <QVariant>
#include <QMessageBox>
#include <QtGui/QApplication>
#include <QSqlError>
#include <QSqlRecord>

const QList<QString> dbInfo::columnNames = 
    QList<QString>() << "name" << "mean" << "date" << "dictName";
const QString dbInfo::tableName = "word";
const QString dbInfo::dbName = "goldendict.db.sqlite";
const QString dbInfo::dbType = "QSQLITE";
const QString dbInfo::sqlSelect = 
    QString("SELECT * FROM %1").arg(dbInfo::tableName);

DB::DB(QObject *parent):QObject(parent)
{
    dbInfo::createConnection();
}

DB::~DB()
{
    //delete model;
}

void DB::fillModel(QSqlTableModel * const model)
{
    //model = new QSqlTableModel(this);
    model->setTable(dbInfo::tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    /// hide the last column
    //model->removeColumn(3);
    //model->removeColumn(1);
    int index = 0;
    foreach(QString name, dbInfo::columnNames)
        model->setHeaderData(index++, Qt::Horizontal, name);
}

void DB::generateRecord(QSqlRecord &record, const QString &word)
{
    record.setValue("name", QVariant(word));
    record.setNull("mean");
    record.setValue("date", QVariant(QDate::currentDate().toString("dd.MM.yyyy")));
    record.setNull("dictName");
}

bool DB::addRow(QString name, QString mean, QString dictName)
{
    /// do the name conversion, remove ending space and to lower case
    name = name.toLower();
    while(name.endsWith(' '))
        name.remove(name.size()-1, 1);

    switch(ifExist(name, dictName))
    {
    case EXIST:
        update(name, mean, dictName);
        break;
    case NO:
    {
        QSqlQuery query;
        query.prepare("INSERT INTO word (name, mean, date, dictName)"
                      "VALUES (?, ?, ?, ?)");
        query.addBindValue(name);
        query.addBindValue(mean);
        query.addBindValue(QDate::currentDate().toString("dd.MM.yyyy"));
        query.addBindValue(dictName);
        /*
        QString cmd = "INSERT INTO ";
        cmd += dbInfo::tableName;
        cmd += '(';
        foreach(QString column, dbInfo::columnNames)
            cmd += column + ',';
        cmd.replace(cmd.size()-1, 1, ')');
        cmd += "VALUES ( name, mean, date, dictName)";
        query.prepare(cmd);
        query.addBindValue(name);
        query.addBindValue(mean);
        query.addBindValue(QDate::currentDate().toString("dd.MM.yyyy"));
        query.addBindValue(other);
        */

        query.exec();
        break;
    }
    case SAME:
        break;
    }

    emit(dbChanged());
    return true;
}
QString DB::dictName(QString name)
{
    name = name.toLower();
    while(name.endsWith(' '))
        name.remove(name.size()-1, 1);

    QString dictName = "";
    QString cmd = QString("SELECT dictName FROM word WHERE name=\'%1\'").arg(name);
    QSqlQuery query;
    query.exec(cmd);
    if (query.next())
        dictName = query.value(0).toString();
    return dictName;
}

DB::status DB::ifExist(QString name, QString dictName )
{
    QSqlQuery query;
    QString cmd = "SELECT COUNT(*) FROM ";
    cmd += dbInfo::tableName;
    cmd += QString(" WHERE name=\'%1\' AND ").arg(name);
    cmd += QString("dictName=\'%1\'").arg(dictName);
    query.prepare(cmd);
    if (!query.exec() || !query.first())
        qDebug() << query.lastError().text();
    else if(query.value(0) != 0) return SAME;

    cmd.clear();
    cmd = "SELECT COUNT(*) FROM ";
    cmd += dbInfo::tableName;
    cmd += QString(" WHERE name=\'%1\' ").arg(name);
    query.prepare(cmd);
    if (!query.exec() || !query.first())
        qDebug() << query.lastError().text();
    else
    {
        if(query.value(0) != 0) return EXIST;
        else return NO;
    }

}

bool DB::update(QString name, QString mean, QString dictName)
{
    QSqlQuery query;
    QString cmd = QString("UPDATE word SET mean = \'%1\' WHERE name = \'%2\'").arg(mean, name);
    query.exec(cmd);

    cmd = QString("UPDATE word SET dictName = \'%1\' WHERE name = \'%2\'").arg(dictName, name);
    query.exec(cmd);

    return true;

}

void DB::removeRow(QString name)
{
    QSqlQuery query;
    QString cmd = QString("DELETE FROM word WHERE name=\'%1\'").arg(name);
    query.exec(cmd);

    emit(dbChanged());
}

bool dbInfo::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(dbInfo::dbType);
    db.setDatabaseName(Config::getDBFileName());
    //db.setDatabaseName(dbInfo::dbName);

    //in the memory
    //db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                              qApp->tr("Unable to establish a database connection.\n"
                                       "This example needs SQLite support. Please read "
                                       "the Qt SQL driver documentation for information how "
                                       "to build it.\n\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS word (ID INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT, mean TEXT, date TEXT, dictName TEXT)");

    query.exec("alter session set NLS_COMP=ANSI");
    query.exec("alter session set NLS_SORT=BINARY_CI");

    return true;
}
