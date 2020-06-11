#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include "log.h"

namespace Ui {
class Info;
}

class Info : public QWidget
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = 0);
    ~Info();

private slots:
    void on_exitbtn_clicked();
    void on_infobtn_clicked();

private:
    Ui::Info *ui;
};

#endif // INFO_H
