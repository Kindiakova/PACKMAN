#include "mainwindow.h"
#include <QApplication>

void generate_map();

int main(int argc, char *argv[])
{
    //generate_map();
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("QMainWindow {background: 'black';}");
    w.show();
    return a.exec();
}

