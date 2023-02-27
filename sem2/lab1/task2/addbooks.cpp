#include "addbooks.h"
#include "ui_addbooks.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

addBooks::addBooks(MainWindow *mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBooks),
    m_mainWindow(mainWindow)
{
    ui->setupUi(this);
}

addBooks::~addBooks()
{
    delete ui;
}
