#ifndef ADD_H
#define ADD_H

#include <QWidget>

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = 0);
    ~Add();

private slots:
    void on_Cancelstudentbtn_clicked();
    void on_addstudentbtn_clicked();
    void Changefunction(const QString);

private:
    Ui::Add *ui;

};

#endif // ADD_H
