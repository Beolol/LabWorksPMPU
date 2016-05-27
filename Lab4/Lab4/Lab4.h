#ifndef LAB4_H
#define LAB4_H

#include <QDialog>
#include <QTextStream>

namespace Ui {
class Lab4;
}

class Lab4 : public QDialog
{
    Q_OBJECT

public:
    explicit Lab4(QWidget *parent = 0);
    ~Lab4();
private:
    void initParams();
    void filingResult();
    QVector<double> calcRunge();
    double f1(double x, double y2 );
    double f2( double x, double y1, double y2 );
private slots:
    void on_calculateButton_clicked();

private:
    Ui::Lab4 *ui;
    QVector<double> Z;
    double x;
    double y1;
    double y2;
};

#endif // LAB4_H
