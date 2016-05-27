#ifndef LAB5_H
#define LAB5_H

#include <QDialog>

namespace Ui {
class Lab5;
}

class Lab5 : public QDialog
{
    Q_OBJECT

public:
    explicit Lab5(QWidget *parent = 0);
    ~Lab5();
private:
    void initParams();
    void filingResult();
    double g(double x);
    QVector<double> calculation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Lab5 *ui;
    QVector<double> f1;
    QVector<double> U;
    QVector<double> C;
    QVector<double> R;
    QVector<double> A;
    QVector<double> B;
    double h;
    int n;
    int m;
};

#endif // LAB5_H
