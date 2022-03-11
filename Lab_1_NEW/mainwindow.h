#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QLineEdit"
#include "QProgressBar"
#include "QPushButton"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* lbl;
    QLineEdit* led1;
    QLineEdit* led2;
    QLineEdit* led3;
    QProgressBar* pgrs;
    QPushButton* btn3;


public slots:
void ReduceNumber();
void IncreaseNumber();
void ChangeProgress();
void ButtonFont();


};
#endif // MAINWINDOW_H







