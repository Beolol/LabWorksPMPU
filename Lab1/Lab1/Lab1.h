#ifndef LAB1_H
#define LAB1_H

#include <QMainWindow>

namespace Ui {
class Lab1;
}

class Lab1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lab1(QWidget *parent = 0);
    ~Lab1();

private:
    Ui::Lab1 *ui;
};

#endif // LAB1_H
