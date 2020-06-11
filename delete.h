#ifndef DELETE_H
#define DELETE_H

#include <QWidget>
#include "log.h"

namespace Ui {
class Delete;
}

class Delete : public QWidget
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = 0);
    ~Delete();

private slots:
    void on_cancelbtn_clicked();
    void on_deletebasebtn_clicked();

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
