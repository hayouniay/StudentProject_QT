#ifndef MODIFY_H
#define MODIFY_H

#include <QWidget>

namespace Ui {
class Modify;
}

class Modify : public QWidget
{
    Q_OBJECT

public:
    explicit Modify(QWidget *parent = 0);
    ~Modify();

private slots:
    void on_modifybtn_clicked();
    void on_cancelbtn_clicked();
    void Dependfunction(const QString);

private:
    Ui::Modify *ui;
};

#endif // MODIFY_H
