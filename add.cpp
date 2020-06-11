#include "add.h"
#include "ui_add.h"
#include "log.h"
#include "dbase.h"

Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    qDebug() <<this->metaObject()->className()<< ": Adding new student to university base";

    QObject::connect(ui->sectioncomboBox, &QComboBox::currentTextChanged, this, &Add::Changefunction);
    // Fill the items of the cours ComboBox
    ui->courscomboBox->clear();
    ui->sectioncomboBox->addItem("A");
    ui->sectioncomboBox->addItem("B");
    ui->sectioncomboBox->addItem("C");
    ui->sectioncomboBox->addItem("D");
    ui->sectioncomboBox->addItem("E");
}

Add::~Add()
{
    delete ui;
}

void Add::Changefunction(const QString)
{
    if (ui->sectioncomboBox->currentText() == "A" )
        {
            ui->courscomboBox->clear();
            ui->courscomboBox->addItem("Maths");
            ui->courscomboBox->addItem("Physics");
        }

    else if (ui->sectioncomboBox->currentText() == "B" )
        {
            ui->courscomboBox->clear();
            ui->courscomboBox->addItem("Maths");
            ui->courscomboBox->addItem("Sciences");
            ui->courscomboBox->addItem("Computer science");
        }
    else if (ui->sectioncomboBox->currentText() == "C" )
        {
            ui->courscomboBox->clear();
             ui->courscomboBox->addItem("Literature");
            ui->courscomboBox->addItem("French");
            ui->courscomboBox->addItem("English");
        }
    else if (ui->sectioncomboBox->currentText() == "D" )
        {
            ui->courscomboBox->clear();
            ui->courscomboBox->addItem("History");
            ui->courscomboBox->addItem("Geography");
        }
    else if (ui->sectioncomboBox->currentText() == "E" )
        {
            ui->courscomboBox->clear();
            ui->courscomboBox->addItem("Arts");
            ui->courscomboBox->addItem("English");
        }
    else
        {
            ui->courscomboBox->clear();
        }

}

void Add::on_addstudentbtn_clicked()
{
    //Set Student info
    QString firstname = ui->firstnameline->text();
    QString lastname = ui->lastnameline->text();
    QString section = ui->sectioncomboBox->currentText();
    QString cour = ui->courscomboBox->currentText();
    //all data must be full
    if ((firstname[0] == '\0') || (lastname[0] == '\0'))
    {
        ui->infolabel->setText("Error: Field(s) must be full !!");
        qDebug() <<this->metaObject()->className()<< ": fill the field(s)";
    }
    else
    {
        QSqlQuery query(DBase::getInstance()->getDBInstance());
        query.prepare("INSERT INTO studentmanagement(firstname, lastname, section, cours) values(:firstname,:lastname,:section, :cour)");
        query.bindValue(":firstname", firstname);
        query.bindValue(":lastname", lastname);
        query.bindValue(":section", section);
        query.bindValue(":cour", cour);

        if(!query.exec())
        {
            qDebug() <<this->metaObject()->className() << query.lastError().text() << query.lastQuery();
            ui->infolabel->setText(query.lastError().text());
        }
        else
        {
            //must check if there is an insertion correctly
            if((query.numRowsAffected() <= 0) || (query.next() == false))
            {
                qDebug() <<this->metaObject()->className()<< ": Student Added to base in database "<< query.lastQuery();
                ui->infolabel->setText("Student registration succeffully !!");
            }
            else
            {
                qDebug() <<this->metaObject()->className()<< "Error: Insertion error "<< query.lastQuery();
                ui->infolabel->setText("Insertion failed, please try again");
            }
        }
    }
}

void Add::on_Cancelstudentbtn_clicked()
{
    //quit only this window
    qDebug() <<this->metaObject()->className()<< ": Cancel registration succefelly";
    ui->firstnameline->clear();
    ui->lastnameline->clear();
    ui->infolabel->clear();
    this->hide();
}
