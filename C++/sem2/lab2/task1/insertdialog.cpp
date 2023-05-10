#include "insertdialog.h"
#include "ui_insertdialog.h"
#include <QMessageBox>

insertDialog::insertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertDialog)
{
    ui->setupUi(this);
}

insertDialog::~insertDialog()
{
    delete ui;
}

void insertDialog::on_buttonBox_accepted()
{
    QString check = ui->lineEdit->text();
    for (int i = 0; i < check.length(); i++) {
        if (!check.at(i).isDigit()) {
            QMessageBox::critical(this,"Error", "Insertion Index must be a number.");
            return;
        }
    }
    int index = ui->lineEdit->text().toInt() - 1;
    check = ui->bookID->text();
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


    emit addBook(index, bookID, bookName, bookAuthor, bookPublisher, bookYear, bookPageAmount);
}

