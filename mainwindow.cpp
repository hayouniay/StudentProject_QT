#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "log.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrMenu = new Menu(this);
    ptrCancel = new Cancel(this);

    connect(ptrMenu, SIGNAL(clicked()), this, SLOT(on_btnmenu_clicked()));
    connect(ptrCancel, SIGNAL(clicked()), this, SLOT(on_btncancel_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnmenu_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Registration in process ...";
    ptrMenu->show();
}

void MainWindow::on_btncancel_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Cancellation in process ...";
    ptrCancel->show();
}
