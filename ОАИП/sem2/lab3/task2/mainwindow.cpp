#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bebra.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bruhButton_clicked()
{
    srand(time(NULL));
    MyVector<pair<MyVector<int>, MyVector<pair<int,double>>>> vec = {{{rand() % 1000, rand() % 1000, rand() % 1000}, {{rand() % 1000, (double(rand() % 1000) / 333)}, {rand() % 1000, (double(rand() % 1000) / 333)}}},
                                                                     {{rand() % 1000, rand() % 1000, rand() % 1000}, {{rand() % 1000, (double(rand() % 1000) / 333)}, {rand() % 1000, (double(rand() % 1000) / 333)}}},
                                                                     {{rand() % 1000, rand() % 1000, rand() % 1000}, {{rand() % 1000, (double(rand() % 1000) / 333)}, {rand() % 1000, (double(rand() % 1000) / 333)}}}};
    std::string a,b;
    for (auto i : vec) {
        for (auto j : i.fir) {
            a += std::to_string(j);
            a += ' ';
        }
        a += '\n';
        for (auto k : i.sec) {
//            b += '(';
            b += std::to_string(k.fir);
            b += ' ';
            b += std::to_string(k.sec);
//            b += ')';
            b += ' ';
        }
        b += '\n';
    }
    ui->firstMat->setText(QString::fromStdString(a));
    ui->secondMat->setText(QString::fromStdString(b));
}

