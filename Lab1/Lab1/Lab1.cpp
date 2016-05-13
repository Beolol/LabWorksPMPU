#include "Lab1.h"
#include "ui_Lab1.h"

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

void Lab1::Method()
{

double f1 (double y);
double f2 (double y);
double f3 (double x);
double f4 (double x);

    FILE *fin;
    int i, j, nn, mm, chet;
    double a, b, eps, xa, yb, z, zz, maxraz, mold;
    double *u, *un;
    printf("Please enter a\n");
    scanf("%lf",&a); //x принадлежит [0;a]
    printf("Please enter number steps by x\n");
    scanf("%d",&nn); //кол-во шагов сетки по x
    printf("Please enter b\n");
    scanf("%lf",&b); //x принадлежит [0;a]
    printf("Please enter number steps by y\n");
    scanf("%d",&mm); //кол-во шагов сетки по y
    printf("Please enter eps\n");
    scanf("%lf",&eps); //точность решения
    xa = a/(nn-1); // шаг по x
    yb = b/(mm-1); // шаг по
    u = malloc(mm*nn*sizeof(double));
    un = malloc(mm*nn*sizeof(double));
    zz = eps;
    maxraz = 2*eps;
    for (i=0;i<nn;i++)
    {
        u[i] = f3(i*xa);
        un[i] = f3(i*xa);
        u[i+nn*(mm-1)] = f4(i*xa);
        un[i+nn*(mm-1)] = f4(i*xa);
    }
    for (j=1;j<nn-1;j++)
    {
        u[j*nn] = f1(j*yb);
        un[j*nn] = f1(j*yb);
        u[nn-1+nn*j] = f2(j*yb);
        un[nn-1+nn*j] = f2(j*yb);
    }
    for (i=1;i<nn-1;i++)
    {
        for (j=1;j<mm-1;j++)
        {
            u[j*nn+i] = 0;
        }
    }
    chet = 0;
    while (maxraz>=zz)
    {
        chet++;
        for (i=1;i<nn-1;i++)
        {
            for (j=1;j<mm-1;j++)
            {
                un[j*nn+i] = (un[(j-1)*nn+i]+un[j*nn+i-1]+u[(j+1)*nn+i]+u[j*nn+i+1])/4;
            }
        }
        mold = maxraz;
        maxraz = 0;
        for (i=1;i<nn-1;i++)
        {
            for (j=1;j<mm-1;j++)
            {
                if (fabs(un[j*nn+i]-u[j*nn+i])>maxraz)
                {
                    maxraz = fabs(un[j*nn+i]-u[j*nn+i]);

                }
            }
        }
        zz = eps*(1-maxraz/mold);
        for (i=1;i<nn-1;i++)
        {
            for (j=1;j<mm-1;j++)
            {
                u[j*nn+i] = un[j*nn+i];
            }
        }
    }
    printf("%d\n", chet);
    fin = fopen("1.txt","w");
    for (j=mm-1;j>-1;j--)
    {
        for (i=0;i<nn-1;i++)
        {
            z = u[i+j*nn];
            z = round(100000*z)/100000;
            fprintf(fin,"%lf\t",z);
        }
        z = u[nn-1+j*nn];
        z = round(100000*z)/100000;
        fprintf(fin,"%lf\n",z);
    }
}

double f1 (double y)
{
    double res, st;
    st = y;
    res = exp(st);
    return(res);
}

double f2 (double y)
{
    double res, st;
    st = 1;
     res = y+exp(st);

    return(res);
}

double f3 (double x)
{
    double res, st;
    st = x*x;
     res = exp(st);
    return(res);
}

double f4 (double x)
{
    double res, st;
    st = x*x+1;
    res = exp(st);
    return(res);
}


