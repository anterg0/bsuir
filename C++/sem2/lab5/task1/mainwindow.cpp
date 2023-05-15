#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "myqueue.cpp"

circular_queue q(10);
QTimer timer;
bool stop = false;


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

void MainWindow::startFunc() {
    if (stop) {
        timer.stop();
        stop = false;
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(true);
        return;
    }
    ui->label_2->setText(q.print());
    q.enqueue(q.front());
    timer.singleShot(150,this,&MainWindow::startFunc);
}


void MainWindow::on_pushButton_clicked()
{

    QString bebra = " ";
    bebra += ui->lineEdit->text();
    q = bebra;
    ui->label_2->setText(bebra);
}


void MainWindow::on_pushButton_2_clicked()
{
    startFunc();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton->setEnabled(false);
}


void MainWindow::on_pushButton_3_clicked()
{
    stop = true;
}

