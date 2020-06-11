#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include "log.h"
#include "dbase.h"

namespace Ui {
class List;
}

class List : public QWidget
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = 0);
    ~List();

private slots:
    void on_listbtn_clicked();
    void on_clearbtn_clicked();

private:
    Ui::List *ui;
};

#endif // LIST_H
