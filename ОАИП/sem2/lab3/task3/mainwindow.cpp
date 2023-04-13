#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bebra.cpp"
#include <QMessageBox>
#include <qDebug>

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


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->vectorEnter->text();
    QStringList list = text.split(' ');
    MyVector<int> bebra;
    for (int i = 0; i < list.size(); i++) {
        bebra.push_back(list[i].toInt());
    }
    MyVector<int> res,temp;
    for (int i = 0, a = 0; i < bebra.size(); i++) {
        temp.push_back(bebra[i]);
        a++;
        if (a == 3) {
            temp.sort();
            res.push_back(temp.at(1));
            temp.clear();
            a = 0;
        }
        if (i == (bebra.size() - 1) && a != 3) {
            int sum = 0;
            for (int j = 0; j < temp.size(); j++) {
                sum += temp[j];
            }
            sum = sum / int(temp.size());
            res.push_back(sum);
            temp.clear();
            break;
        }
    }
    QString result = "Median: (";
    for (int i = 0; i < res.size(); i++) {
        if (i == res.size() - 1) {
            result += QString::number(res[i]);
            result += ')';
        } else {
            result += QString::number(res[i]);
            result += ", ";
        }
    }
    ui->label_2->setText(result);
}

