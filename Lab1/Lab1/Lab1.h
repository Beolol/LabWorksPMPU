#ifndef LAB1_H
#define LAB1_H

#include <QMainWindow>

namespace Ui {
class Lab1;
}

class Lab1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lab1(QWidget *parent = 0);
    ~Lab1();
    double f1( double y );
    double f2( double y );
    double f3( double x );
    double f4( double x );

    void GetSizeUAndUn();
    void SetUAndUn();
    void Calculation();
    void FilingResult();

private slots:
    void on_btnStart_clicked();

private:
    Ui::Lab1 *ui;
    QVector<double> U;
    QVector<double> Un;
    int gridOfX;
    int gridOfY;
};

#endif // LAB1_H
