#include "Lab3.h"
#include "ui_Lab3.h"

#include <QFile>

Lab3::Lab3(QWidget *parent) :
    QDialog(parent),
    x(0),
    y1(0),
    y2(0),
    ui(new Ui::Lab3)
{
    ui->setupUi(this);
}

Lab3::~Lab3()
{
    delete ui;
}

void Lab3::on_calculateButton_clicked()
{
    InitParams();
    FilingResult();
}

void Lab3::InitParams()
{
    for( int i = 0; i < 3; i++ )
    {
       Z.push_back(0);
    }
}

void Lab3::recordResult(QTextStream *file)
{

}

QVector<double> Lab3::culculation()
{
    QVector<double> result;
    auto h = ui->sboxH->value();
    result.push_back( x + h );
    result.push_back( y1 + h * cos( y1*y2 ) );
    result.push_back( y2 + h * cos( y1+y2 ) );
    return result;
}


void Lab3::FilingResult()
{
    QFile file("3.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << x << "\t" << y1 << "\t" << y2 << "\n";
    for( int i = 0 ; i < ui->sboxN->value(); i++ )
    {
        Z = culculation();
        x = Z[0];
        y1 = Z[1];
        y2 = Z[2];
        out << x << "\t" << y1 << "\t" << y2 << "\n";
    }
    file.close();
}

