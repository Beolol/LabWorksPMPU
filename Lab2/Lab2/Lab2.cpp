#include "Lab2.h"
#include "ui_Lab2.h"

#include <QFile>
#include <QTextStream>

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

QVector<double> Lab2::Calculation( double lya )
{
    QVector<double> result;
    QVector<double> matr;
    QVector<double> ost;
    int r = gridOfX - 2;
    for( int i = 0; i < r*r ; i++ )
    {
        matr.push_back( 0 );
    }

    for( int i=0; i<r; i++)
    {
        ost.push_back( -Bas[i+1] );
    }
    ost[0]-= lya * ui->sboxA->value();
    ost[r-1]-= lya * ui->sboxB->value();
    matr[0] = -1-2*lya;
    matr[1] = lya;
    matr[r*r-2] = lya;
    matr[r*r-1] = -1-2*lya;
    for( int i = 1; i<r-1; i++ )
    {
        matr[i*(r+1)] = -1-2*lya;
        matr[i*(r+1)-1] = lya;
        matr[i*(r+1)+1] = lya;
    }
    QVector<double> x;
    x.push_back( 0 );
    for( int i = 1; i<r; i++ )
    {
        x.push_back( 0 );
        auto koe = matr[i*(r+1)-1]/matr[(i-1)*(r+1)];
        for ( int j = i-1; j < r; j++ )
        {
            matr[i*r+j] -= koe*matr[(i-1)*r+j];
        }
        ost[i] -= koe*ost[i-1];
    }
    x[r-1] = ost[r-1]/matr[r*r-1];
    for( int i=r-2; i>-1; i-- )
    {
        x[i] = ost[i];
        for( int j=r-1; j>i ;j-- )
        {
            x[i] -= matr[i*r+j]*x[j];
        }
        x[i]/=matr[i*(r+1)];
    }
    result.push_back( ui->sboxA->value() );
    for( int i=1; i<r+1; i++ )
    {
        result.push_back( x[i-1] );
    }
    result.push_back( ui->sboxB->value() );
    return result;
}

void Lab2::SetParams()
{
    auto xa = 1.0/(gridOfX-1);
    double lya = ui->sboxLengthStepGridT->value()/xa/xa;
    for (int i=0;i<gridOfX;i++)
    {
        Bas[i] = f1(i*xa);
        U[i] = Bas[i];
    }
    for( int i=1; i<gridOfT; i++ )
    {
        Bas = Calculation( lya );
        for( int j=0; j<gridOfX; j++ )
        {
            U[j+i*gridOfX] = Bas[j];
        }
    }
    QFile file("2.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    for( int i = gridOfT-1; i > -1; i-- )
    {
        for( int j=0; j < gridOfX-1; j++ )
        {
            out << U[j+i*gridOfX] << "\t";
        }
        out << U[gridOfX-1+i*gridOfX] << "\n";
    }
    file.close();
}

void Lab2::on_btnStart_clicked()
{
    SetSizeVectors();
    SetParams();
}
