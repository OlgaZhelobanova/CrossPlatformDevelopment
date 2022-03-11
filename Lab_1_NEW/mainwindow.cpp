#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QLabel"
#include "QLineEdit"
#include "QGridLayout"
#include "QProgressBar"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        QPushButton* btn1 = new QPushButton("-");
        QPushButton* btn2 = new QPushButton("+");
        btn3 = new QPushButton("Ok");
        lbl = new QLabel("Введите число и диапазон его изменения");
        led1 = new QLineEdit;
        led2 = new QLineEdit;
        led3 = new QLineEdit;
        pgrs = new QProgressBar;

       QObject::connect(btn1,SIGNAL(clicked(bool)),this, SLOT(ReduceNumber()));
       QObject::connect(btn1,SIGNAL(clicked(bool)),this, SLOT(ChangeProgress()));
       QObject::connect(btn2,SIGNAL(clicked(bool)),this, SLOT(IncreaseNumber()));
       QObject::connect(btn2,SIGNAL(clicked(bool)),this, SLOT(ChangeProgress()));
       QObject::connect(btn3,SIGNAL(clicked(bool)),this, SLOT(ChangeProgress()));
       QObject::connect(pgrs,SIGNAL(valueChanged(int)),this, SLOT(ButtonFont()));


        btn1 ->setFixedWidth(50);
        btn2 ->setFixedWidth(50);
        btn3 ->setFixedWidth(50);

        led2 ->setFixedWidth(50);
        led3 ->setFixedWidth(50);



        QString stl = "alignment: central";
        btn1 -> setStyleSheet(stl);

        QGridLayout* glayout = new QGridLayout();

        glayout->addWidget(lbl,0,1, Qt::AlignCenter);
        glayout->addWidget(btn1,2,0,2,1, Qt::AlignRight);
        glayout->addWidget(btn2,2,2,2,1, Qt::AlignLeft);
        glayout->addWidget(btn3,4,2,2,1, Qt::AlignRight);
        glayout->addWidget(led1,1,1,2,1, Qt::AlignCenter);
        glayout->addWidget(led2,1,0,2,1, Qt::AlignCenter);
        glayout->addWidget(led3,1,2,2,1, Qt::AlignCenter);
        glayout->addWidget(pgrs,2,1,2,1);

        QWidget* wdg = new QWidget();
        wdg->setLayout(glayout);//привязка компоновки к виджету

        this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::ReduceNumber()
{
    if (led2->text()==nullptr||led3->text()==nullptr)
    {lbl -> setText("Вы не ввели значения диапазона");}
    else
    {
    int A,const1;
     const1=led2->text().toInt();
     A=led1->text().toInt();

    if(A>const1)
    {
    lbl->setText(" ");


    A=led1->text().toInt();
    A=A-1;
    led1->setText(QString::number(A));
    }

    else lbl -> setText("Дальнейшее уменьшение невозможно!");
    }
}

void MainWindow::IncreaseNumber()
{
    if (led2->text()==nullptr||led3->text()==nullptr)
    {lbl -> setText("Вы не ввели значения диапазона");}
    else
    {
    int A,const1;
     const1=led3->text().toInt();
     A=led1->text().toInt();

    if(A<const1)
    {
    lbl->setText(" ");


    A=led1->text().toInt();
    A=A+1;
    led1->setText(QString::number(A));
    }

    else lbl -> setText("Дальнейшее увеличение невозможно!");
    }
}

void MainWindow::ChangeProgress()
{
    if (led2->text()==nullptr||led3->text()==nullptr)
    {lbl -> setText("Вы не ввели значения диапазона");
        pgrs->setFormat("%v");

    }
    else{
    int A,B,C;

    A=led3->text().toInt();
    B=led2->text().toInt();
    C=led1->text().toInt();

    pgrs -> setMinimum(B);
    pgrs -> setMaximum(A);

    pgrs->setTextVisible(true);
    pgrs->setFormat("%v");
    pgrs->setAlignment(Qt::AlignCenter);
    pgrs -> setValue(C);
    }

}

void MainWindow::ButtonFont()
{
    QString stl = "font-size: %1pt";
    QString stl2 = stl.arg(pgrs->value()+5);

    btn3->setStyleSheet(stl2);
}
