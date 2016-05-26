#include "Lab3.h"
#include "ui_Lab3.h"

Lab3::Lab3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lab3)
{
    ui->setupUi(this);
}

Lab3::~Lab3()
{
    delete ui;
}
