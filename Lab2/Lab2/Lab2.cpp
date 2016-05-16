#include "Lab2.h"
#include "ui_Lab2.h"

Lab2::Lab2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lab2)
{
    ui->setupUi(this);
}

Lab2::~Lab2()
{
    delete ui;
}

double Lab2::f1(double x, double a, double b, double c)
{
    if(x <= c)
    {
        return(a);
    }
    else
    {
        return(a+(b-a)*(x-c)/(1-c));
    }
}

void Lab2::on_btnStart_clicked()
{

}

