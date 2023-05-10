#include "bookinfo.h"
#include "ui_bookinfo.h"
#include "mainwindow.h"

bookInfo::bookInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookInfo)
{
    ui->setupUi(this);
}

bookInfo::~bookInfo()
{
    delete ui;
}

void bookInfo::enterInfo(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount) {
    ui->id->setText(QString::number(bookID));
    ui->name->setText(bookName);
    ui->author->setText(bookAuthor);
    ui->publisher->setText(bookPublisher);
    ui->year->setText(QString::number(bookYear));
    ui->pages->setText(QString::number(bookPageAmount));
}
