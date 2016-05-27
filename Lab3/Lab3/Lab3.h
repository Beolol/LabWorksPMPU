#ifndef LAB3_H
#define LAB3_H

#include <QDialog>
#include <QTextStream>

namespace Ui {
class Lab3;
}

class Lab3 : public QDialog
{
    Q_OBJECT

public:
    explicit Lab3(QWidget *parent = 0);
    ~Lab3();

private slots:
    void on_calculateButton_clicked();
private:
    void InitParams();
    void FilingResult();
    QVector<double> culculation();
    void recordResult( QTextStream * file );
private:
    Ui::Lab3 *ui;
    QVector<double> Z;
    double x;
    double y1;
    double y2;
};

#endif // LAB3_H
