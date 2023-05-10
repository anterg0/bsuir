#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "bebra.cpp"

MyVector<int> v1{1,2,3,4,5,6,7};
MyVector<int> v2{10,39,228,1377,1337,69};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    printVectors();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printVectors() {
    QString firstVec;
    QString secondVec;
    for (int i = 0; i < v1.size(); i++) {
        firstVec += QString::number(v1[i]);
        firstVec += " ";
    }
    for (int i = 0; i < v2.size(); i++) {
        secondVec += QString::number(v2[i]);
        secondVec += " ";
    }
    ui->v1Elements->setText(firstVec);
    ui->v2Elements->setText(secondVec);
    ui->v1MaxSize->setText(QString::number(v1.capacity()));
    ui->v2MaxSize->setText(QString::number(v2.capacity()));
}

void MainWindow::on_v1Push_clicked()
{
    QString val = ui->pushValue->text();
    bool isDigit = true;
    bool noSpaces = true;
    for (auto& beb : val) {
        if (beb == ' ') {
            noSpaces = false;
        }
        if (!beb.isDigit()) {
            isDigit = false;
            break;
        }
    }
    if (!noSpaces) {
        QMessageBox::critical(this,"Error","Remove any spaces you've entered.");
        return;
    }
    if (!isDigit) {
        QMessageBox::critical(this,"Error","Value should be an int.");
        return;
    }
    int value = val.toInt();
    v1.push_back(value);
    printVectors();
}


void MainWindow::on_swapVec_clicked()
{
    v1.swap(v2);
    printVectors();
}


void MainWindow::on_v2Push_clicked()
{
    QString val = ui->pushValue->text();
    bool isDigit = true;
    bool noSpaces = true;
    for (auto& beb : val) {
        if (beb == ' ') {
            noSpaces = false;
        }
        if (!beb.isDigit()) {
            isDigit = false;
            break;
        }
    }
    if (!noSpaces) {
        QMessageBox::critical(this,"Error","Remove any spaces you've entered.");
        return;
    }
    if (!isDigit) {
        QMessageBox::critical(this,"Error","Value should be an int.");
        return;
    }
    int value = val.toInt();
    v2.push_back(value);
    printVectors();
}


void MainWindow::on_v1Pop_clicked()
{
    v1.pop_back();
    printVectors();
}


void MainWindow::on_v2Pop_clicked()
{
    v2.pop_back();
    printVectors();
}


void MainWindow::on_v1Clear_clicked()
{
    v1.clear();
    printVectors();
}


void MainWindow::on_v2Clear_clicked()
{
    v2.clear();
    printVectors();
}


void MainWindow::on_v1Resize_clicked()
{
    QString val = ui->resizeValue->text();
    bool isDigit = true;
    bool noSpaces = true;
    for (auto& beb : val) {
        if (beb == ' ') {
            noSpaces = false;
        }
        if (!beb.isDigit()) {
            isDigit = false;
            break;
        }
    }
    if (!noSpaces) {
        QMessageBox::critical(this,"Error","Remove any spaces you've entered.");
        return;
    }
    if (!isDigit) {
        QMessageBox::critical(this,"Error","Value should be an int.");
        return;
    }
    int value = val.toInt();
    v1.resize(value);
    printVectors();
}


void MainWindow::on_v2Resize_clicked()
{
    QString val = ui->resizeValue->text();
    bool isDigit = true;
    bool noSpaces = true;
    for (auto& beb : val) {
        if (beb == ' ') {
            noSpaces = false;
        }
        if (!beb.isDigit()) {
            isDigit = false;
            break;
        }
    }
    if (!noSpaces) {
        QMessageBox::critical(this,"Error","Remove any spaces you've entered.");
        return;
    }
    if (!isDigit) {
        QMessageBox::critical(this,"Error","Value should be an int.");
        return;
    }
    int value = val.toInt();
    v2.resize(value);
    printVectors();
}


void MainWindow::on_v1At_clicked()
{
    QString val = ui->atValue->text();
    bool isDigit = true;
    bool noSpaces = true;
    for (auto& beb : val) {
        if (beb == ' ') {
            noSpaces = false;
        }
        if (!beb.isDigit()) {
            isDigit = false;
            break;
        }
    }
    if (!noSpaces) {
        QMessageBox::critical(this,"Error","Remove any spaces you've entered.");
        return;
    }
    if (!isDigit) {
        QMessageBox::critical(this,"Error","Value should be an int.");
        return;
    }
    int value = val.toInt() - 1;
    if (value + 1 > v1.size() || value + 1 == 0) {
        QMessageBox::critical(this,"error", "Out of range.");
        return;
    }
    QString result = "Element of v1 at this index is: " + QString::number(v1.at(value));
    QMessageBox::information(this,"Element",result);
}


void MainWindow::on_v2At_clicked()
{
    QString val = ui->atValue->text();
    bool isDigit = true;
    bool noSpaces = true;
    for (auto& beb : val) {
        if (beb == ' ') {
            noSpaces = false;
        }
        if (!beb.isDigit()) {
            isDigit = false;
            break;
        }
    }
    if (!noSpaces) {
        QMessageBox::critical(this,"Error","Remove any spaces you've entered.");
        return;
    }
    if (!isDigit) {
        QMessageBox::critical(this,"Error","Value should be an int.");
        return;
    }
    int value = val.toInt() - 1;
    if (value + 1 > v2.size() || value + 1 == 0) {
        QMessageBox::critical(this,"error", "Out of range.");
        return;
    }
    QString result = "Element of v2 at this index is: " + QString::number(v2.at(value));
    QMessageBox::information(this,"Element",result);
}

