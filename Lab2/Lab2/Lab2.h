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
    void SetParams();
    void SetSizeVectors();
    QVector<double> Calculation(double lya);
    double f1(double x);
private slots:
    void on_btnStart_clicked();

private:
    Ui::Lab2 *ui;
    QVector<double> U;
    QVector<double> Bas;
    int gridOfX;
    int gridOfT;
};

#endif // LAB2_H
