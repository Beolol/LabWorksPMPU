#ifndef LAB2_H
#define LAB2_H

#include <QDialog>

namespace Ui {
class Lab2;
}

class Lab2 : public QDialog
{
    Q_OBJECT

public:
    explicit Lab2(QWidget *parent = 0);
    ~Lab2();

private:
    Ui::Lab2 *ui;
};

#endif // LAB2_H
