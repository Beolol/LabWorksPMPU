#ifndef LAB4_H
#define LAB4_H

#include <QDialog>

namespace Ui {
class Lab4;
}

class Lab4 : public QDialog
{
    Q_OBJECT

public:
    explicit Lab4(QWidget *parent = 0);
    ~Lab4();

private:
    Ui::Lab4 *ui;
};

#endif // LAB4_H
