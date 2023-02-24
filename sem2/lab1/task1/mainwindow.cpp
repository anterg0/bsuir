#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include <QFileDialog>
#include <fstream>

Date bruh[100];
int count = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Текущая дата: " + QDate::currentDate().toString("dd.MM.yyyy"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    QFileDialog dialog;
    QString fileName = dialog.getOpenFileName();
    std::ifstream file;
    file.open(fileName.toStdString());
    if (file.is_open()) {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
    }
    std::string date;
    while (!file.eof()) {
        file >> date;
        int row = ui->tableWidget->rowCount();
        bruh[row].setDate(QDate::fromString(QString::fromStdString(date), "dd.MM.yyyy"));
        ui->tableWidget->insertRow(row);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(date));
        ui->tableWidget->setItem(row,0,item);
    }
    file.close();
    for (int i = 0; i <= ui->tableWidget->rowCount();i++) {
        for (int j = 0; j <= ui->tableWidget->columnCount();j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (item) {
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
        }
    }
    ui->spinBox->setMaximum(ui->tableWidget->rowCount());
}


void MainWindow::on_pushButton_2_clicked() {
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();
    for (int i = 1; i <= cols;i++) {
        for (int j = 0; j <= rows; j++) {
            if (i == 1) {
                QTableWidgetItem *item = ui->tableWidget->item(j,0);
                if (item) {
                    QString textDate = item->text();
                    QDate qNewDate = bruh[j].NextDay(QDate::fromString(textDate,"dd.MM.yyyy"));
                    QString newDate = qNewDate.toString("dd.MM.yyyy");
                    QTableWidgetItem *newItem = new QTableWidgetItem(newDate);
                    ui->tableWidget->setItem(j,1,newItem);
                }
            }
            if (i == 2) {
                QTableWidgetItem *item = ui->tableWidget->item(j + 1,0);
                if (item) {
                    QString textDate = item->text();
                    int diff = bruh[j].Duration(QDate::fromString(textDate, "dd.MM.yyyy"));
                    QString newDate = QString::number(diff);
                    QTableWidgetItem *newItem = new QTableWidgetItem(newDate);
                    ui->tableWidget->setItem(j,2,newItem);
                } else {
                    QTableWidgetItem *item = new QTableWidgetItem("-");
                    ui->tableWidget->setItem(j,2,item);
                }
            }
            if (i == 3) {
                QTableWidgetItem *item = ui->tableWidget->item(j,0);
                if (item) {
                    QString textDate = item->text();
                    QDate date = QDate::fromString(textDate, "dd.MM.yyyy");
                    if (date.isLeapYear(date.year())) {
                        QTableWidgetItem *newItem = new QTableWidgetItem("+");
                        ui->tableWidget->setItem(j,3,newItem);
                    } else {
                        QTableWidgetItem *newItem = new QTableWidgetItem("-");
                        ui->tableWidget->setItem(j,3,newItem);
                    }
                }
            }
        }
    }
    for (int i = 0; i <= ui->tableWidget->rowCount();i++) {
        for (int j = 0; j <= ui->tableWidget->columnCount();j++) {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if (item) {
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }
        }
    }
}


void MainWindow::on_pushButton_3_clicked() {
    int rows = ui->tableWidget->rowCount();
    QDate entDate = ui->dateEdit->date();
    bruh[rows].setDate(entDate);
    QTableWidgetItem *item = new QTableWidgetItem(entDate.toString("dd.MM.yyyy"));
    ui->tableWidget->insertRow(rows);
    ui->tableWidget->setItem(rows,0,item);
    ui->spinBox->setMaximum(ui->tableWidget->rowCount());
}


void MainWindow::on_pushButton_4_clicked() {
    int row = ui->spinBox->value() - 1;
    ui->tableWidget->removeRow(row);
    ui->spinBox->setMaximum(ui->tableWidget->rowCount());
}


void MainWindow::on_pushButton_6_clicked() {
    for (int i = 0; i < ui->tableWidget->rowCount();i++) {
    QDate dr = ui->dateEdit_2->date();
    int days = bruh[i].DaysTillYourBirthday(dr);
    QTableWidgetItem *item = new QTableWidgetItem(QString::number(days));
    ui->tableWidget->setItem(i,4,item);
    int daysSince = bruh[i].Duration(dr);
    item = new QTableWidgetItem(QString::number(daysSince));
    ui->tableWidget->setItem(i,5,item);
    }
}

