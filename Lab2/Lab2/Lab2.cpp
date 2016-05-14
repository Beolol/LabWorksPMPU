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

void Lab2::on_btnStart_clicked()
{

}
