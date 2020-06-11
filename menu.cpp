#include "menu.h"
#include "ui_menu.h"
#include "log.h"


Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ptrAdd = new Add();
    ptrList = new List();
    ptrModify = new Modify();
    ptrDelete = new Delete();
    ptrInfo = new Info();

    connect(ui->addbtn, SIGNAL(clicked()), this, SLOT(on_btnadd_clicked()));
    connect(ui->infobtn, SIGNAL(clicked()), this, SLOT(on_btninfo_clicked()));
    connect(ui->deletebtn, SIGNAL(clicked()), this, SLOT(on_btndelete_clicked()));
    connect(ui->modifybtn, SIGNAL(clicked()), this, SLOT(on_btnmodify_clicked()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_exitbtn_clicked()
{
    //quit only this window
    qDebug() <<this->metaObject()->className()<< ": Cancel registration from main menu succefelly !!";
    this->close();
}

void Menu::on_listbtn_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": List SUniversity base in Menu";
    ptrList->show();
}

void Menu::on_btnadd_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Adding new Student to the base";
    ptrAdd->show();
}

void Menu::on_btninfo_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Getting Student info";
    ptrInfo->show();
}

void Menu::on_btndelete_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Delete Student from base";
    ptrDelete->show();
}

void Menu::on_btnmodify_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Modifying Student informations";
    ptrModify->show();
}


