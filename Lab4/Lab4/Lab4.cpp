#include "Lab4.h"
#include "ui_Lab4.h"

#include <QFile>


Lab4::Lab4(QWidget *parent) :
    QDialog(parent),
    x(-1),
    y1(0.5),
    y2(0),
    ui(new Ui::Lab4)
{
    ui->setupUi(this);
}

Lab4::~Lab4()
{
    delete ui;
}

void Lab4::initParams()
{
    for( int i = 0; i < 3; i++ )
    {
       Z.push_back(0);
    }
}

void Lab4::filingResult()
{
    QFile file("4.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << x << "\t" << y1 << "\t" << y2 << "\n";
    for( int i = 0 ; i < ui->sboxN->value(); i++ )
    {
        Z = calcRunge();
        x = Z[0];
        y1 = Z[1];
        y2 = Z[2];
        out << x << "\t" << y1 << "\t" << y2 << "\n";
    }
    file.close();
}

QVector<double> Lab4::calcRunge()
{
    QVector<double> result;
    auto h = ui->sboxH->value();
    auto k11 = f1( x,y2 );
    auto k21 = f2( x, y1, y2 );
    auto k12 = f1( x+h/2, y2+h*k21/2 );
    auto k22 = f2( x+h/2, y1+h*k11/2, y2+h*k21/2 );
    auto k13 = f1( x+h/2, y2+h*k22/2 );
    auto k23 = f2( x+h/2, y1+h*k12/2, y2+h*k22/2 );
    auto k14 = f1( x+h, y2+h*k23 );
    auto k24 = f2( x+h, y1+h*k13, y2+h*k23 );
    result.push_back( x+h );
    result.push_back( y1+h/6*(k11+2*k12+2*k13+k14 ) );
    result.push_back( y2+h/6*(k21+2*k22+2*k23+k24 ) );
    return result;
}

double Lab4::f1(double x, double y2)
{
    double res;
    res = x/(sqrt(1.0+x*x+y2*y2));
    return res;
}

double Lab4::f2(double x, double y1, double y2)
{
    double res;
    res = y2/(sqrt(1.0+x*x+y1*y1));
    return res;
}

void Lab4::on_calculateButton_clicked()
{
    initParams();
    filingResult();
}
