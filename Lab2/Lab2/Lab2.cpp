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


double Lab2::f1(double x)
{
    auto a = ui->sboxA->value();
    auto b = ui->sboxB->value();
    auto c = ui->sboxC->value();
    if(x <= c)
    {
        return(a);
    }
    else
    {
        return(a+(b-a)*(x-c)/(1-c));
    }
}

void Lab2::SetSizeVectors()
{
    gridOfX = ui->editGridNumberX->value();
    gridOfT = ui->editGridNumberT->value();
    for( int i = 0; i< gridOfX * gridOfT; i++ )
    {
        U.push_back( 0 );
        if( i < gridOfX )
            Bas.push_back( 0 );
    }
}

QVector<double> Lab2::Calculation()
{
    QVector<double> result;
    return result;
}

void Lab2::SetParams()
{
    auto xa = 1.0/(gridOfX-1);
//    auto lya = ui->sboxLengthStepGridT->value()/xa/xa;
    for (int i=0;i<gridOfX;i++)
    {
        Bas[i] = f1(i*xa);
        U[i] = Bas[i];
    }
    for (int j=1;j<gridOfT;j++)
    {
        Bas = Calculation();

    }
}

void Lab2::on_btnStart_clicked()
{
    SetSizeVectors();
    SetParams();
}
