#include "Lab5.h"
#include "ui_Lab5.h"

#include <QFile>
#include <QTextStream>


Lab5::Lab5(QWidget *parent) :
    QDialog(parent),
    h(0.2),
    n(4),
    m(5),
    ui(new Ui::Lab5)
{
    ui->setupUi(this);
}

Lab5::~Lab5()
{
    delete ui;
}

void Lab5::initParams()
{
    for( int i = 0; i < n*m; i++ )
    {
        f1.push_back(0);
    }
    f1[0] = -1.7863;
    f1[1] = -1.7832;
    f1[2] = -1.7838;
    f1[3] = -1.7878;
    f1[n+0] = -1.6877;
    f1[n+1] = -1.6776;
    f1[n+2] = -1.6709;
    f1[n+3] = -1.6673;
    f1[2*n+0] = -1.5994;
    f1[2*n+1] = -1.5838;
    f1[2*n+2] = -1.5714;
    f1[2*n+3] = -1.5630;
    f1[3*n+0] = -1.5200;
    f1[3*n+1] = -1.5000;
    f1[3*n+2] = -1.4832;
    f1[3*n+3] = -1.4692;
    f1[4*n+0] = -1.4480;
    f1[4*n+1] = -1.4246;
    f1[4*n+2] = -1.4043;
    f1[4*n+3] = -1.3869;
    for( int i = 0; i < n; i++ )
    {
        U.push_back(0);
        C.push_back(0);
        R.push_back(0);
        A.push_back(0);
        B.push_back(0);
    }
}

double Lab5::g( double x )
{
    return 2*x*x + 2*x - 4;
}
QVector<double> Lab5::calculation()
{
    QVector<double> result, al, bet;
    for( int i = 0; i < n; i++ )
    {
        result.push_back(0);
        al.push_back(0);
        bet.push_back(0);
    }
    if( C[0] != 0 )
    {
        al[1] = -B[0]/C[0];
        bet[1] = R[0]/C[0];
    }
    for( int i=2; i<n; i++ )
    {
        al[i] = -B[i-1]/(A[i-1]*al[i-1]+C[i-1]);
        bet[i] = (R[i-1]-A[i-1]*bet[i-1])/(A[i-1]*al[i-1]+C[i-1]);
    }
    result[n-1] = (R[n-1]-A[n-1]*bet[n-1])/(C[n-1]+A[n-1]*al[n-1]);
    for( int i = n-2; i>-1; i-- )
    {
        result[i] = al[i+1]*result[i+1] + bet[i+1];
    }
    return result;
}

void Lab5::filingResult()
{
    QFile file("5.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    for( int i=0; i<m; i++ )
    {
        auto al = 0.7+0.05*i;
        for( int j=0; j<m; j++ )
        {
            for( int k=0; k<4; k++ )
            {
                C[k] = cos(al*(k+1)*h)-2.0/h/h;
                R[k] = g((k+1)*h);
            }
            for (i=0;i<3;i++)
            {
                A[i+1] = 1.0/h/h-f1[i+1+4*j]/2/h;
                B[i] = 1.0/h/h+f1[i+4*j]/2/h;
            }
            U = calculation();
            for (i=0;i<n;i++)
            {
                out << U[i] << "\n";
            }
        }
    }
    file.close();
}

void Lab5::on_pushButton_clicked()
{
    initParams();
    filingResult();
}
