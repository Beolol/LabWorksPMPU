#include "Lab4.h"
#include "ui_Lab4.h"

Lab4::Lab4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lab4)
{
    ui->setupUi(this);
}

Lab4::~Lab4()
{
    delete ui;
}
