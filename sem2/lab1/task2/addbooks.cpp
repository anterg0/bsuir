#include "addbooks.h"
#include "ui_addbooks.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

addBooks::addBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBooks)
{
    ui->setupUi(this);
}

addBooks::~addBooks()
{
    delete ui;
}
