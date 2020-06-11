#ifndef MENU_H
#define MENU_H


#include <QDialog>
#include "add.h"
#include "list.h"
#include "info.h"
#include "modify.h"
#include "delete.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_exitbtn_clicked();
    void on_listbtn_clicked();
    void on_btnadd_clicked();
    void on_btninfo_clicked();
    void on_btnmodify_clicked();
    void on_btndelete_clicked();


private:
    Ui::Menu *ui;
    Add *ptrAdd;
    List *ptrList;
    Info *ptrInfo;
    Modify *ptrModify;
    Delete *ptrDelete;
};

#endif // MENU_H
