#include "delete.h"
#include "ui_delete.h"
#include "dbase.h"

Delete::Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_deletebasebtn_clicked()
{
    bool Exist = false;
    //Get Student info by ID
    int idstudent = ui->linedelete->text().toInt();
    if(idstudent < 1)
    {
        ui->infolabel->setText("Error Student not exist: please verify your id");
        qDebug() <<this->metaObject()->className()<< "Error: Please verify ID";
    }
    else
    {
        QSqlQuery query(DBase::getInstance()->getDBInstance());
        query.prepare("DELETE FROM studentmanagement WHERE id = :idstudent");
        query.bindValue(":idstudent", idstudent);

        if(!query.exec())
        {
            qDebug() <<this->metaObject()->className() << query.lastError().text() << query.lastQuery();
            ui->infolabel->setText(query.lastError().text());
        }
        else
        {
            //check if it really deleted from table
            Exist = query.next();
            if(Exist)
            {
                qDebug() <<this->metaObject()->className()<< "Info: Student was deleted successfully "<< query.lastQuery();
                ui->infolabel->setText("Informations deleted successfully !!");
            }
            else
            {
                qDebug() <<this->metaObject()->className()<< "Error : Student Not exist in database "<< query.lastQuery();
                ui->infolabel->setText("Student not registred, Please make the registration first");
            }
        }
    }

}

void Delete::on_cancelbtn_clicked()
{
    //quit only this window
    qDebug() <<this->metaObject()->className()<< ": Exit";
    // just clean table after exit
    ui->linedelete->clear();
    ui->infolabel->clear();
    qDebug() <<this->metaObject()->className()<< ": Clear informations ...";
    this->hide();
}
