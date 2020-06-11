#ifndef DBASE_H
#define DBASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>
#include <QSqlQueryModel>
#include "log.h"

class DBase
{
private:
    DBase();
    static DBase *instance;
    void init();
    QSqlDatabase db;
public:
    static DBase* getInstance();
    static void ResetInstance();
    QSqlDatabase getDBInstance();
    ~DBase();
};


#endif // DBASE_H
