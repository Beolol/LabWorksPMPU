#ifndef LAB2_H
#define LAB2_H

#include <QDialog>

namespace Ui {
class Lab2;
}

class Lab2 : public QDialog
{
    Q_OBJECT

public:
    explicit Lab2(QWidget *parent = 0);
    ~Lab2();
    InitParams();
    double f1(double x, double a, double b, double c);
private slots:
    void on_btnStart_clicked();

private:
    Ui::Lab2 *ui;
};

#endif // LAB2_H
