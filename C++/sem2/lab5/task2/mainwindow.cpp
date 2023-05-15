#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydeque.cpp"
#include <QMessageBox>
MyDeque<int> deque(10);

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


void MainWindow::on_emptyButton_clicked()
{
    QMessageBox::information(this,"empty?", deque.empty() ? "it's empty." : "it's not empty.");
}


void MainWindow::on_sizeButton_clicked()
{
    QMessageBox::information(this,"deque size", "it's this big: " + QString::number(deque.size()));
}


void MainWindow::on_clearButton_clicked()
{
    deque.clear();
    QMessageBox::information(this,"deque is cleared", "deque has been cleared");
}


void MainWindow::on_pushB_clicked()
{
    QString inputText = ui->lineEdit->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        deque.push_back(inputText.toInt());
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_pushF_clicked()
{
    QString inputText = ui->lineEdit->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        deque.push_front(inputText.toInt());
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_popF_clicked()
{
    QMessageBox::information(this,"pop_front",QString::number(deque.pop_front()));
}


void MainWindow::on_popB_clicked()
{
    QMessageBox::information(this,"pop_front",QString::number(deque.pop_back()));
}

