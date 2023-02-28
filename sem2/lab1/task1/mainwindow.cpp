#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "savesuccess.h"
#include "ui_savesuccess.h"
#include "date.h"
#include <QFileDialog>
#include <fstream>

Date bruh[100];
QString fileName;

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
    QString check = fileName;
    QFileDialog dialog;
    fileName = dialog.getOpenFileName(this,nullptr,QDir::homePath(),tr("Text files (*.txt)"));
    std::ifstream file;
    file.open(fileName.toStdString());
    if (file.eof()) {

    }
    if (file.is_open()) {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
    } else return;
    std::string date;
    while (!file.eof()) {
        file >> date;
        int row = ui->tableWidget->rowCount();
        QDate dateCheck = QDate::fromString(QString::fromStdString(date), "dd.MM.yyyy");
        if (!dateCheck.isValid()) continue;
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
    if (ui->tableWidget->rowCount() == 0) {
        if (check.isEmpty()) fileName = "";
        else fileName = check;
        saveSuccess *window = new saveSuccess();
        window->ui->label->setText("Неправильный формат файла.");
        window->show();
    }
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
                    if (QDate::fromString(textDate, "dd.MM.yyyy") <= QDate(1,1,1)) {
                        QTableWidgetItem *newItem = new QTableWidgetItem("До нашей эры");
                        ui->tableWidget->setItem(j,1,newItem);
                    } else {
                        QDate qNewDate = bruh[j].PreviousDay(QDate::fromString(textDate,"dd.MM.yyyy"));
                        QString newDate = qNewDate.toString("dd.MM.yyyy");
                        QTableWidgetItem *newItem = new QTableWidgetItem(newDate);
                        ui->tableWidget->setItem(j,1,newItem);
                    }
                }
            }
            if (i == 2) {
                QTableWidgetItem *item = ui->tableWidget->item(j,0);
                if (item) {
                    QString textDate = item->text();
                    QDate qNewDate = bruh[j].NextDay(QDate::fromString(textDate,"dd.MM.yyyy"));
                    QString newDate = qNewDate.toString("dd.MM.yyyy");
                    QTableWidgetItem *newItem = new QTableWidgetItem(newDate);
                    ui->tableWidget->setItem(j,2,newItem);
                }
            }
            if (i == 3) {
                QTableWidgetItem *item = ui->tableWidget->item(j + 1,0);
                if (item) {
                    QString textDate = item->text();
                    int diff = bruh[j].Duration(QDate::fromString(textDate, "dd.MM.yyyy"));
                    QString newDate = QString::number(diff);
                    QTableWidgetItem *newItem = new QTableWidgetItem(newDate);
                    ui->tableWidget->setItem(j,3,newItem);
                } else {
                    QTableWidgetItem *item = new QTableWidgetItem("-");
                    ui->tableWidget->setItem(j,3,item);
                }
            }
            if (i == 4) {
                QTableWidgetItem *item = ui->tableWidget->item(j,0);
                if (item) {
                    QString textDate = item->text();
                    QDate date = QDate::fromString(textDate, "dd.MM.yyyy");
                    if (date.isLeapYear(date.year())) {
                        QTableWidgetItem *newItem = new QTableWidgetItem("+");
                        ui->tableWidget->setItem(j,4,newItem);
                    } else {
                        QTableWidgetItem *newItem = new QTableWidgetItem("-");
                        ui->tableWidget->setItem(j,4,newItem);
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
    for (int i = 0; i < ui->tableWidget->rowCount();i++) {
        QTableWidgetItem *item = ui->tableWidget->item(i,0);
        QString textDate = item->text();
        bruh[i].setDate(QDate::fromString(textDate, "dd.MM.yyyy"));
    }
}


void MainWindow::on_pushButton_6_clicked() {
    for (int i = 0; i < ui->tableWidget->rowCount();i++) {
        QDate dr = ui->dateEdit_2->date();
        int days = bruh[i].DaysTillYourBirthday(dr);
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(days));
        ui->tableWidget->setItem(i,5,item);
        int daysSince = bruh[i].birthdayDuration(dr);
        item = new QTableWidgetItem(QString::number(daysSince));
        ui->tableWidget->setItem(i,6,item);
    }
}


void MainWindow::on_pushButton_5_clicked() {
    saveSuccess *newWindow = new saveSuccess(this);
    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::homePath(), tr("Text files (*.txt)"));
        if (fileName.isEmpty()) {
            return;
        }

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            newWindow->ui->label->setText("Не удалось сохранить файл.");
            newWindow->show();
            return;
        }

        QTextStream out(&file);
        for (int i = 0; i < ui->tableWidget->rowCount();i++) {
            QString text = ui->tableWidget->item(i,0)->text();
            if (i != ui->tableWidget->rowCount() - 1) out << text + '\n';
            else out << text;
        }
        file.close();
        newWindow->ui->label->setText("Файл был сохранен.");
        newWindow->show();
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&file);
        for (int i = 0; i < ui->tableWidget->rowCount();i++) {
            QString text = ui->tableWidget->item(i,0)->text();
            if (i != ui->tableWidget->rowCount() - 1) out << text + '\n';
            else out << text;
        }
        file.close();
        newWindow->ui->label->setText("Файл был сохранен.");
        newWindow->show();
    }
}


void MainWindow::on_pushButton_7_clicked()  {
    fileName = "";
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
}

