#include "Lab1.h"
#include "ui_Lab1.h"


#include <QDebug>
#include <QFile>

Lab1::Lab1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lab1)
{
    ui->setupUi(this);

}

Lab1::~Lab1()
{
    delete ui;
}


void Lab1::on_btnStart_clicked()
{
    GetSizeUAndUn();
    SetUAndUn();
    Calculation();
    FilingResult();
}

void Lab1::GetSizeUAndUn()
{
    auto countStepX = ui->editGridNumberX->value();
    auto countStepY = ui->editGridNumberY->value();
    for( int i = 0; i< countStepX * countStepY; i++ )
    {
        U.push_back( 0 );
        Un.push_back( 0 );
    }
}

void Lab1::SetUAndUn()
{
    gridOfX = ui->editGridNumberX->value();
    gridOfY = ui->editGridNumberY->value();
    auto stepX = ui->editRightX->value()/ (gridOfX-1);
    auto stepY = ui->editRightY->value()/ (gridOfY-1);
    for (int i=0;i< gridOfX; i++)
    {
        U[i] = f3(i*stepX);
        Un[i] = f3(i*stepX);
        U[i+gridOfX*(gridOfY-1)] = f4(i*stepX);
        Un[i+gridOfX*(gridOfY-1)] = f4(i*stepX);
    }
    for (int j=1;j<gridOfX;j++)
    {
        U[j*(gridOfX+1)] = f1(j*stepY);
        Un[j*(gridOfX+1)] = f1(j*stepY);
        U[gridOfX-1+gridOfX*j] = f2(j*stepY);
        Un[gridOfX-1+gridOfX*j] = f2(j*stepY);
    }
    for (int i=1;i<gridOfX-1;i++)
    {
        for (int j=1;j<gridOfY-1;j++)
        {
            U[j*gridOfX+i] = 0;
        }
    }
}

double Lab1::f1(double y)
{
    auto res = exp( y );
    return res;
}

double Lab1::f2(double y)
{
    auto res = y + exp( 1 );
    return res;
}

double Lab1::f3(double x)
{
    auto res = exp( x*x );
    return res;
}

double Lab1::f4(double x)
{
    auto res = exp(x*x+1);
    return res;
}


void Lab1::Calculation()
{
    int count = 0;
    auto maxError = 2 * ui->editEps->value();
    auto error = ui->editEps->value();

    while (maxError>=error)
    {
        count++;
        for (int i=1;i<gridOfX-1;i++)
        {
            for (int j=1;j<gridOfY-1;j++)
            {
                Un[j*gridOfX+i] = (Un[(j-1)*gridOfX+i]+Un[j*gridOfX+i-1]
                                    +U[(j+1)*gridOfX+i]+U[j*gridOfX+i+1])/4;
            }
        }
        auto mold = maxError;
        maxError = 0;
        for (int i=1;i<gridOfX-1;i++)
        {
            for (int j=1;j<gridOfY-1;j++)
            {
                if (fabs(Un[j*gridOfX+i]-U[j*gridOfX+i])>maxError)
                {
                    maxError = fabs(Un[j*gridOfX+i]-U[j*gridOfX+i]);

                }
            }
        }
        error = ui->editEps->value()*(1-maxError/mold);
        for (int i=1;i<gridOfX-1;i++)
        {
            for (int j=1;j<gridOfY-1;j++)
            {
                U[j*gridOfX+i] = Un[j*gridOfX+i];
            }
        }
    }
    qDebug() << count;
}



void Lab1::FilingResult()
{
    QFile file("1.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    double z;
    for (int j=gridOfY-1;j>-1;j--)
    {
        for (int i=0;i<gridOfX-1;i++)
        {
            z = U[i+j*gridOfX];
            z = round(100000*z)/100000;
            out << z << "\t";
        }
        z = U[gridOfX-1+j*gridOfX];
        z = round(100000*z)/100000;
        out << z << "\t";
    }
    file.close();
}
