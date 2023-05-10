#include "adddialog.h"
#include "ui_adddialog.h"
#include <QMessageBox>

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::setEdit(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount) {
    ui->bookAuthor->setText(bookAuthor);
    ui->bookName->setText(bookName);
    ui->bookID->setText(QString::number(bookID));
    ui->bookPublisher->setText(bookPublisher);
    ui->bookYear->setText(QString::number(bookYear));
    ui->bookPageAmount->setText(QString::number(bookPageAmount));
}

void addDialog::on_buttonBox_accepted()
{
    QString check = ui->bookID->text();
    for (int i = 0; i < check.length(); i++) {
        if (!check.at(i).isDigit()) {
            QMessageBox::critical(this,"Error", "ID must be a number.");
            return;
        }
    }
    int bookID = ui->bookID->text().toInt();
    QString bookName = ui->bookName->text();
    QString bookAuthor = ui->bookAuthor->text();
    QString bookPublisher = ui->bookPublisher->text();
    check = ui->bookYear->text();
    for (int i = 0; i < check.length(); i++) {
        if (!check.at(i).isDigit()) {
            QMessageBox::critical(this,"Error", "Year must be a number.");
            return;
        }
    }
    int bookYear = ui->bookYear->text().toInt();
    check = ui->bookPageAmount->text();
    for (int i = 0; i < check.length(); i++) {
        if (!check.at(i).isDigit()) {
            QMessageBox::critical(this,"Error", "Page Amount must be a number.");
            return;
        }
    }
    int bookPageAmount = ui->bookPageAmount->text().toInt();

    emit addBook(bookID, bookName, bookAuthor, bookPublisher, bookYear, bookPageAmount);
}

