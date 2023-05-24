#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>
#include "hashtable.cpp"
#include <QMessageBox>
HashTable table(128);
int attempts = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int bebra;
    for (int i = 0; i <= 100; i++) {
        bebra = 150 * i;
        bebra += 11;
        table.insert(bebra);
    }

    ui->plot->addGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddButton_clicked()
{
    QString inputText = ui->AddLine->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        if (inputText.toInt() == -1) {
            QMessageBox::warning(this,"error","Don't use this number, please.");
        }
        table.insert(inputText.toInt());
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < table.getSize(); i++) {
        if (table[i] != -1) qDebug() << table[i];
    }
    qDebug() << '\n';
    table.printTable();
}


void MainWindow::on_SearchButton_clicked()
{
    QString inputText = ui->SearchLine->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        auto start_time = clock();
        int search = table.search(inputText.toInt());
        long double duration = (long double)(clock () - start_time) / CLOCKS_PER_SEC;
        if (search == -1) {
            QMessageBox::information(this,"Search","There's no such value");
            return;
        }
        qDebug() << QString::number(duration,'f',7);
        ui->plot->graph(0)->addData(++attempts,duration);
        ui->plot->rescaleAxes();
        ui->plot->replot();
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_ModuloButton_clicked()
{
    QString inputText = ui->ModuloLine->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        if (inputText.toInt() < 0) {
            QMessageBox::warning(this,"error","Value should be positive.");
            return;
        }
        table.setModulo(inputText.toInt());
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_SearchLine_returnPressed()
{
    on_SearchButton_clicked();
}

