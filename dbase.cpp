#include "dbase.h"

DBase* DBase::instance = nullptr;

DBase::DBase()
{
    init();
}

DBase::~DBase()
{
   qDebug() << "closing database connection";
   db.close();
}

void DBase::init()
{
    qDebug() << "in init()";
    db = QSqlDatabase::addDatabase("QSQLITE", "Data");
    db.setDatabaseName("/home/hayouniaymen/Documents/QT_Projects/StudentManagement/student");

    if(QFile::exists("/home/hayouniaymen/Documents/QT_Projects/StudentManagement/student"))
    {
        qDebug() << "DBase file exist";
    }
    else
    {
        qDebug() << "DBase file doesn't exists";
    }

    if (!db.open()){
        qDebug() << db.lastError().text();
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    else{
        qDebug() << "Database loaded successfull!";
    }

}

/*void DBase::Listtable(QString flag = "y")
{
        //std::vector<int> student;

        QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
        Database.setDatabaseName("/home/hayouniaymen/Documents/QT_Projects/StudentManagement/student.sql");
        if(QFile::exists("/home/hayouniaymen/Documents/QT_Projects/StudentManagement/student.sql"))
            qDebug() << "DBase file exist";
        else
           qDebug() << "DBase file doesn't exists";

        if (!Database.open())
            qDebug() << Database.lastError().text();
        else
            qDebug() << "Database loaded successfull!";

        QSqlQuery query(Database);
        query.prepare("select number from student where available = '" + flag + "'");

        if(!query.exec())
            qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "Fetch was successful";

        while(query.next())
        {
            QString record = query.value(0).toString();
            rooms.push_back(record.toInt());
            qDebug()<<"Line is : "<<record;
        }

        Database.close();
}*/

DBase *DBase::getInstance()
{
    qDebug() << "in DBase::getInstance()";
    if(instance == nullptr){
        instance = new DBase();
    }

    return instance;
}

QSqlDatabase DBase::getDBInstance()
{
    qDebug() <<"in getDBInstance()";
    return db;
}

void DBase::ResetInstance()
{
      qDebug() << "deleting instance of DBase";
      delete instance;
      instance = nullptr;
}
