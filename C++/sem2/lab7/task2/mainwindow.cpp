#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "set.cpp"
#include "map.cpp"
#include <QMessageBox>

MySet<int> myset;
MyMap<int,int> mymap;

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

void MainWindow::UpdateSetTable() {
    ui->tableSet->clearContents();
    ui->tableSet->setRowCount(0);
    if (myset.isEmpty()) return;
    int numElements = 0;
    for (const auto& value : myset) {
        numElements++;
    }
    ui->tableSet->setRowCount(numElements);
    int row = 0;
    for (const auto& value : myset)
    {
        QTableWidgetItem* keyItem = new QTableWidgetItem(QString::number(value));
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(value));

        ui->tableSet->setItem(row, 0, keyItem);
        ui->tableSet->setItem(row, 1, valueItem);

        row++;
    }
    ui->tableSet->resizeColumnsToContents();
    ui->tableSet->resizeRowsToContents();
}

void MainWindow::UpdateMapTable() {
    ui->tableMap->clearContents();
    ui->tableMap->setRowCount(0);
    if (mymap.isEmpty()) return;
    int numElements = 0;
    for (const auto& value : mymap) {
        numElements++;
    }
    ui->tableMap->setRowCount(numElements);
    int row = 0;
    for (const auto& value : mymap)
    {
        QTableWidgetItem* keyItem = new QTableWidgetItem(QString::number(value.first));
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::number(value.second));

        ui->tableMap->setItem(row, 0, keyItem);
        ui->tableMap->setItem(row, 1, valueItem);

        row++;
    }
    ui->tableMap->resizeColumnsToContents();
    ui->tableMap->resizeRowsToContents();
}

void MainWindow::on_addSet_clicked()
{
    if (ui->addValSet->text().toInt()) {
        int key = ui->addValSet->text().toInt();
        myset.InsertNode(key);
        UpdateSetTable();
    } else {
        QMessageBox::warning(this,"Error","That's not an int.");
    }
}


void MainWindow::on_delSet_clicked()
{
    if (ui->delValSet->text().toInt()) {
        int key = ui->delValSet->text().toInt();
        myset.remove(key);
        UpdateSetTable();
    } else {
        QMessageBox::warning(this,"Error","That's not an int.");
    }
}


void MainWindow::on_findSet_clicked()
{
    if (ui->findValSet->text().toInt()) {
        int key = ui->findValSet->text().toInt();
        Node<int>* search = myset.search(key);
        if (search) QMessageBox::information(this,"Found element!", "Here's your element: " + QString::number(search->key));
        else QMessageBox::warning(this,"Error","That element doesn't exist.");
    } else {
        QMessageBox::warning(this,"Error","That's not an int.");
    }
}


void MainWindow::on_outputSet_clicked()
{
    if (myset.isEmpty()) {
        QMessageBox::warning(this,"error","Set is empty.");
        return;
    }
    QString output;
    for (const auto& value : myset) {
        output += (QString::number(value) + " ");
    }
    ui->outputLabelSet->setText(output);
}


void MainWindow::on_clearSet_clicked()
{
    myset.clear();
    UpdateSetTable();
}


void MainWindow::on_addMap_clicked()
{
    if (ui->addValMap->text().toInt() && ui->addKeyMap->text().toInt()) {
        pair<int,int> temp(ui->addKeyMap->text().toInt(),ui->addValMap->text().toInt());
        mymap.insert_map(temp);
        UpdateMapTable();
    }
}

