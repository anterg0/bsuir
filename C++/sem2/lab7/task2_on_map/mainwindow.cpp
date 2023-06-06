#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unordered_map.cpp"
#include <QMessageBox>
HashTable<int, std::string> table;
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


void MainWindow::on_insertButton_clicked()
{
    if (ui->insKey->text().toInt() && !(ui->insValue->text().isEmpty())) {
        std::string val = ui->insValue->text().toStdString();
        int key = ui->insKey->text().toInt();
        table.insert(key,val);
        ui->insValue->clear();
        ui->insKey->clear();
    } else {
        QMessageBox::warning(this,"Error","Something is wrong. (key is not int or value is empty)");
    }
}


void MainWindow::on_containsButton_clicked()
{
    if (ui->containsKey->text().toInt()) {
        int key = ui->containsKey->text().toInt();
        if (table.contains(key)) QMessageBox::information(this,"Found element.","Here's the value of that key: " + QString::fromStdString(table[key]));
        else QMessageBox::warning(this,"Error","Key wasn't found");
        ui->containsKey->clear();
    } else {
        QMessageBox::warning(this,"Error","Something is wrong. (key is not int or value is empty)");
    }
}


void MainWindow::on_outputButton_clicked()
{
    ui->outputText->clear();
    for(const auto& bucket : table.getBuckets())
    {
        for (const auto& entry : bucket)
        {
            ui->outputText->insertPlainText("Key: " + QString::number(entry.first) + ", Value: " + QString::fromStdString(entry.second) + '\n');
        }
    }
}


void MainWindow::on_clearButtton_clicked()
{
    ui->outputText->clear();
    table.clear();
}

