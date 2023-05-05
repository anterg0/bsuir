#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
#include <QMessageBox>
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


void MainWindow::on_strncpyString1_clicked()
{
    int num = ui->strncpyNum->value();
    std::string str = ui->strncpyLine->text().toStdString();
    mystrncpy(string1.c_str(),str.c_str(),num);
    Refresh();
}


void MainWindow::on_strncpyString2_clicked()
{
    int num = ui->strncpyNum->value();
    std::string str = ui->strncpyLine->text().toStdString();
    mystrncpy(string2.c_str(),str.c_str(),num);
    Refresh();
}


void MainWindow::on_strcatString1_clicked()
{
    std::string str = ui->strcatLine->text().toStdString();
    mystrcat(string1.c_str(),str.c_str());
    Refresh();
}


void MainWindow::on_strcatString2_clicked()
{
    std::string str = ui->strcatLine->text().toStdString();
    mystrcat(string2.c_str(),str.c_str());
    Refresh();
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << string1.toQString() << "\n" << string2.toQString() << "\n";
}


void MainWindow::on_strncatString1_clicked()
{
    int num = ui->strncatNum->value();
    std::string str = ui->strncatLine->text().toStdString();
    mystrncat(string1.c_str(),str.c_str(),num);
    Refresh();
}


void MainWindow::on_strncatString2_clicked()
{
    int num = ui->strncatNum->value();
    std::string str = ui->strncatLine->text().toStdString();
    mystrncat(string2.c_str(),str.c_str(),num);
    Refresh();
}


void MainWindow::on_memsetString1_clicked()
{
    int num = ui->memsetNum->value();
    std::string str = ui->memsetLine->text().toStdString();
    mymemset(string1.c_str(),str.front(),num);
    Refresh();
}


void MainWindow::on_memsetString2_clicked()
{
    int num = ui->memsetNum->value();
    std::string str = ui->memsetLine->text().toStdString();
    mymemset(string2.c_str(),str.front(),num);
    Refresh();
}


void MainWindow::on_strcmpString1_clicked()
{
    std::string str = ui->strcmpLine->text().toStdString();
    QMessageBox::information(this,"Result","Result: " + QString::number(mystrcmp(string1.c_str(),str.c_str())));
}


void MainWindow::on_strcmpString2_clicked()
{
    std::string str = ui->strcmpLine->text().toStdString();
    QMessageBox::information(this,"Result","Result: " + QString::number(mystrcmp(string2.c_str(),str.c_str())));
}


void MainWindow::on_strncmpString1_clicked()
{
    int num = ui->strncmpNum->value();
    std::string str = ui->strcmpLine->text().toStdString();
    QMessageBox::information(this,"Result","Result: " + QString::number(mystrncmp(string1.c_str(),str.c_str(),num)));
}


void MainWindow::on_strncmpString2_clicked()
{
    int num = ui->strncmpNum->value();
    std::string str = ui->strcmpLine->text().toStdString();
    QMessageBox::information(this,"Result","Result: " + QString::number(mystrncmp(string2.c_str(),str.c_str(),num)));
    qDebug() << strncmp(string2.c_str(),str.c_str(),num);
}

