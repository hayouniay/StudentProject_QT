#include "list.h"
#include "ui_list.h"

List::List(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);
    qDebug() <<this->metaObject()->className()<< ": List all registred students List()";
}

List::~List()
{
    delete ui;
}

void List::on_listbtn_clicked()
{
    QSqlQuery query(DBase::getInstance()->getDBInstance());
    query.prepare("SELECT firstname, lastname, section, cours FROM studentmanagement ");

    if(!query.exec())
    {
        qDebug() <<this->metaObject()->className() << query.lastError().text() << query.lastQuery();
        ui->labelinfo->setText(query.lastError().text());
    }
    else
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        modal->setQuery(query);
        ui->databasetable->setModel(modal);
        qDebug() <<this->metaObject()->className()<< ": Students Informations display was successful "<< query.lastQuery();
        //to display the first row
        query.first();
        int idstudent = query.value(0).toInt();
        QString firstname = query.value(1).toString();
        QString lastname = query.value(2).toString();
        QString section = query.value(3).toString();
        QString cour = query.value(4).toString();
        qDebug() <<this->metaObject()->className()<< "Student ID :"<<idstudent<<"family name: "<<firstname
                <<"Name: "<<lastname << "Section: "<< section <<"cours: "<< cour;
        while(query.next())
        {
            int idstudent = query.value(0).toInt();
            QString firstname = query.value(1).toString();
            QString lastname = query.value(2).toString();
            QString section = query.value(3).toString();
            QString cour = query.value(4).toString();
            qDebug() <<this->metaObject()->className()<< "Student ID :"<<idstudent<<"family name: "<<firstname
                    <<"Name: "<<lastname << "Section: "<< section <<"cours: "<< cour;
        }
        ui->labelinfo->setText("Display was successful!");
        qDebug() <<this->metaObject()->className()<< ": student number="<<(modal->rowCount());
    }
}

void List::on_clearbtn_clicked()
{
    QSqlQuery query(DBase::getInstance()->getDBInstance());
    query.prepare("SELECT * FROM studentmanagement ");
    QSqlQueryModel * modal = new QSqlQueryModel();
    modal->setQuery(query);
    ui->databasetable->setModel(modal);
    qDebug() <<this->metaObject()->className()<< ": Clear display ...";
    modal->clear();
    ui->labelinfo->setText("View is cleaned !!");
}
