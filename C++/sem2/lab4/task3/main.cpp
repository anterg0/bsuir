#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon("/Users/anterg0/Desktop/parser.png");
    QApplication::setWindowIcon(icon);
    MainWindow w;
    w.show();
    return a.exec();
}
