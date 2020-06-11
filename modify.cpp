#include "modify.h"
#include "ui_modify.h"
#include "log.h"
#include "dbase.h"


Modify::Modify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);

    QObject::connect(ui->sectioncombox, &QComboBox::currentTextChanged, this, &Modify::Dependfunction);
    // Fill the items of the cours ComboBox
    ui->sectioncombox->clear();
    ui->sectioncombox->addItem("A");
    ui->sectioncombox->addItem("B");
    ui->sectioncombox->addItem("C");
    ui->sectioncombox->addItem("D");
    ui->sectioncombox->addItem("E");
}

Modify::~Modify()
{
    delete ui;
}

void Modify::Dependfunction(const QString)
{
    if (ui->sectioncombox->currentText() == "A" )
    {
        ui->courscombox->clear();
        ui->courscombox->addItem("Maths");
        ui->courscombox->addItem("Physics");
    }
    else if (ui->sectioncombox->currentText() == "B" )
    {
        ui->courscombox->clear();
        ui->courscombox->addItem("Maths");
        ui->courscombox->addItem("Sciences");
        ui->courscombox->addItem("Computer science");
    }
    else if (ui->sectioncombox->currentText() == "C" )
    {
        ui->courscombox->clear();
        ui->courscombox->addItem("Literature");
        ui->courscombox->addItem("French");
        ui->courscombox->addItem("English");
    }
    else if (ui->sectioncombox->currentText() == "D" )
    {
        ui->courscombox->clear();
        ui->courscombox->addItem("History");
        ui->courscombox->addItem("Geography");
    }
    else if (ui->sectioncombox->currentText() == "E" )
    {
        ui->courscombox->clear();
        ui->courscombox->addItem("Arts");
        ui->courscombox->addItem("English");
    }
    else
    {
        ui->courscombox->clear();
    }
}

void Modify::on_modifybtn_clicked()
{
    //Set Student info
    int idstudent = ui->idline->text().toInt();
    QString firstname = ui->linefirstname->text();
    QString lastname = ui->linelastname->text();
    QString section = ui->sectioncombox->currentText();
    QString cour = ui->courscombox->currentText();
    //all data must be full
    if ((firstname[0] == '\0') || (lastname[0] == '\0') || idstudent<1)
    {
        ui->labelinfo->setText("Error: Field(s) must be set correctlly !!");
        qDebug() <<this->metaObject()->className()<< ": fill the field(s) correctlly";
    }
    else
    {
        QSqlQuery query(DBase::getInstance()->getDBInstance());
        query.prepare("UPDATE studentmanagement SET firstname=:firstname, lastname=:lastname, section=:section, cours=:cour WHERE id=:idstudent");
        query.bindValue(":idstudent", idstudent);
        query.bindValue(":firstname", firstname);
        query.bindValue(":lastname", lastname);
        query.bindValue(":section", section);
        query.bindValue(":cour", cour);

        if(!query.exec())
        {
            qDebug() <<this->metaObject()->className() << query.lastError().text() << query.lastQuery();
            ui->labelinfo->setText(query.lastError().text());
        }
        else
        {
            //must check if there is an update correctly
            if((query.numRowsAffected() <= 0) || (query.next() == false))
            {
                qDebug() <<this->metaObject()->className()<< ": Update student informations success"<< query.lastQuery();
                ui->labelinfo->setText("Update informations succeffully !!");
            }
            else
            {
                qDebug() <<this->metaObject()->className()<< "Error: update terminate with error "<< query.lastQuery();
                ui->labelinfo->setText("Update failed, please try again");
            }
        }
    }

}

void Modify::on_cancelbtn_clicked()
{
    //quit only this window
    qDebug() <<this->metaObject()->className()<< ": Exit";
    ui->idline->clear();
    ui->linefirstname->clear();
    ui->linelastname->clear();
    ui->labelinfo->clear();
    this->hide();
}
