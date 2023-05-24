#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hashtable.cpp"
#include <QMessageBox>

DerivedHashTable table(5);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    for (int i = 0; i < 40; i++) {
        int key = rand() % 1000000;
        table.insert(key);
        std::cout << "Inserted " << key << " in stack #" << key % 5 << std::endl;
    }
    bebra();
}

void MainWindow::bebra() {
    QString result;
    for (int i = 0; i < 5; i++) {
        QString text = table.getStackContents(i);
        result += text;
    }
    ui->plainTextEdit->setPlainText(result);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    int maxStackIndex = table.getIndexOfMaxStack();

    if (maxStackIndex != -1) {
        QMessageBox::information(this,"Max Stack","Index of the stack with the biggest number: " + QString::number(maxStackIndex));
    } else {
        QMessageBox::information(this,"Max Stack","No stacks with numbers found.");
    }
}


void MainWindow::on_pushButton_clicked()
{
    table.clear();
    srand(time(NULL));
    for (int i = 0; i < 40; i++) {
        int key = rand() % 1000000;
        table.insert(key);
        std::cout << "Inserted " << key << " in stack #" << key % 5 << std::endl;
    }
    bebra();
}

