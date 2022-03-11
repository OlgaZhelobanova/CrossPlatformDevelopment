#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Первое приложение на Qt");
    w.resize(250, 250);
    w.show();
    return a.exec();
}
