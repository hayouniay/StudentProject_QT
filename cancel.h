#ifndef CANCEL_H
#define CANCEL_H

#include <QDialog>

namespace Ui {
class Cancel;
}

class Cancel : public QDialog
{
    Q_OBJECT

public:
    explicit Cancel(QWidget *parent = 0);
    ~Cancel();

private slots:
    void on_cancelbtn_clicked();

private:
    Ui::Cancel *ui;
};

#endif // CANCEL_H
