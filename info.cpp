#include "info.h"
#include "ui_info.h"
#include "dbase.h"
#include <QSqlRecord>

Info::Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);

}

Info::~Info()
{
    delete ui;
}

void Info::on_infobtn_clicked()
{
    bool Exist = false;
    //Get Student info by ID
    int idstudent = ui->idline->text().toInt();
    if(idstudent < 1)
    {
        ui->infolabel->setText("Student not exist !!\n please verify your id first");
        qDebug() <<this->metaObject()->className()<< "Info: Please verify ID";
    }
    else
    {
        QSqlQuery query(DBase::getInstance()->getDBInstance());
        query.prepare("SELECT firstname, lastname, section, cours FROM studentmanagement WHERE id = :idstudent");
        query.bindValue(":idstudent", idstudent);

        if(!query.exec())
        {
            qDebug() <<this->metaObject()->className() << query.lastError().text() << query.lastQuery();
            ui->infolabel->setText(query.lastError().text());
        }
        else
        {
            Exist = query.next();
            if(Exist)
            {
                QSqlQueryModel * modal = new QSqlQueryModel();
                modal->setQuery(query);
                ui->studenttable->setModel(modal);
                query.first();
                qDebug() <<this->metaObject()->className()<< "Info: Student Informations display successfully "<< query.lastQuery();
                QString firstname = query.value(0).toString();
                QString lastname = query.value(1).toString();
                QString section = query.value(2).toString();
                QString cour = query.value(3).toString();
                qDebug() <<this->metaObject()->className()<< "Student ID :"<<idstudent<<"family name: "<<firstname
                        <<"Name: "<<lastname << "Section: "<< section <<"cours: "<< cour;
                ui->infolabel->setText("Informations display successfully");
            }
            else
            {
                qDebug() <<this->metaObject()->className()<< "Error : Student Not exist in database "<< query.lastQuery();
                ui->infolabel->setText("Student not registred, Please make the registration first");
            }
        }
    }

}

void Info::on_exitbtn_clicked()
{
    //quit only this window
    qDebug() <<this->metaObject()->className()<< ": Exit";
    // just clean table after exit
    ui->idline->clear();
    QSqlQuery query(DBase::getInstance()->getDBInstance());
    query.prepare("SELECT * FROM studentmanagement ");
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery(query);
    ui->studenttable->setModel(modal);
    qDebug() <<this->metaObject()->className()<< ": Clear display ...";
    modal->clear();
    ui->infolabel->clear();
    this->hide();
}
