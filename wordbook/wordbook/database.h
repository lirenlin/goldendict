#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QObject>
#include <QList>

class QSqlTableModel;

class DB: public QObject
{
    Q_OBJECT
public:
    DB(QObject *parent = 0);
    virtual ~DB();

    enum status {
        SAME,
        EXIST,
        NO
    };
    QSqlTableModel * getModel();

public slots:
    bool addRow(QString name, QString mean, QString dictName);
    QString dictName(QString name);
    void removeRow(QString name);

    void removeRow(int row);
    status ifExist(QString name, QString dictName = "");

private:
    bool update(QString name, QString mean, QString dictName);
    void fillModel();

    QSqlTableModel *model;

signals:
    void dbChanged();
};

class dbInfo
{
public:
    static const QList<QString> columnNames;
    static const QString tableName ;
    static const QString dbName;
    static const QString dbType;
    static const QString sqlSelect;
    static bool createConnection();

};

#endif // DATABASE_H
