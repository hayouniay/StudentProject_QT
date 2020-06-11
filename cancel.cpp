#include "cancel.h"
#include "ui_cancel.h"
#include "log.h"

Cancel::Cancel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cancel)
{
    ui->setupUi(this);
}

Cancel::~Cancel()
{
    delete ui;
}

void Cancel::on_cancelbtn_clicked()
{
    //quit only this window
    qDebug() <<this->metaObject()->className()<< ": Exit from project registration succefelly !!";
    this->close();
    //quit main window
    qApp->quit();
}
