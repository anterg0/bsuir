#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
MyString string1 = "Bebra";
MyString string2 = "Aboba";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Refresh() {
    QString s1 = string1.toQString();
    QString s2 = string2.toQString();
    int sl1 = mystrlen(s1.toStdString().c_str());
    int sl2 = mystrlen(s2.toStdString().c_str());
    ui->strlen1->setText(QString::number(sl1));
    ui->strlen2->setText(QString::number(sl2));
    ui->string1Edit->setText(s1);
    ui->string2Edit->setText(s2);
}

void MainWindow::on_changeString1_clicked()
{
    QString text = ui->changeStringLine->text();
    mystrcpy(string1.c_str(),text.toStdString().c_str());

    Refresh();
}


void MainWindow::on_changeString2_clicked()
{
    QString text = ui->changeStringLine->text();
    string2 = text.toStdString();
    Refresh();
}

