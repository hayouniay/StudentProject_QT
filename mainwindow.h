#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include "cancel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnmenu_clicked();
    void on_btncancel_clicked();


private:
    Ui::MainWindow *ui;
    Menu *ptrMenu;
    Cancel *ptrCancel;
};

#endif // MAINWINDOW_H
