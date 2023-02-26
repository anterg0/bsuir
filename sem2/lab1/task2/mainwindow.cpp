#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reader.h"
#include "addbooks.h"
#include "ui_addbooks.h"
#include "findname.h"
#include "ui_findname.h"
#include <QRandomGenerator>
#include <QFile>
#include <QFileDialog>

Reader *readers = new Reader[1000];
QList<Book> books;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QComboBox* MainWindow::getComboBox() {
    return ui->comboBox;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete[] readers;
}

void MainWindow::on_pushButton_clicked() {
    QFileDialog dialog;
    QFile file(dialog.getOpenFileName(this,nullptr,QDir::homePath(), tr("Text files (*.txt)")));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file";
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" ");
        if (parts.size() < 6) {
            qDebug() << "Invalid line format: " << line;
            continue;
        }
        int id = parts[0].toInt();
        QString fullName = parts[1] + ' ' + parts[2] + ' ' + parts[3];
        QString phoneNumber = parts[4];
        QString contactAddress;
        for (int i = 5; i < parts.size(); i++) contactAddress += parts[i] + ' ';
        contactAddress.erase(contactAddress.end(),contactAddress.end());
        int count = ui->comboBox->count();
        readers[count] = Reader(id, fullName, phoneNumber, contactAddress);
        ui->comboBox->addItem(readers[count].getName());
    }
    file.close();

}


void MainWindow::on_comboBox_activated(int index) {
    int id = readers[index].getID();
    QString address = readers[index].getAddress();
    QString number = readers[index].getNumber();
    ui->addr->setText(address);
    ui->phone->setText(number);
    ui->id->setText(QString::number(id));
    QList<Book> list = readers[index].getBorrowedBooks();
    for (int i = 0; i < list.size(); i++) {
        ui->listWidget->clear();
        QListWidgetItem *item = new QListWidgetItem(list[i].name);
        ui->listWidget->addItem(item);
    }
}


void MainWindow::on_addBook_clicked()  {
    addBooks *newWindow = new addBooks();
    newWindow->show();
}

void addBooks::on_pushButton_2_clicked() {
    QString text1 = ui->readerID->text();
    int id = text1.toInt();
    QString text2 = ui->bookID->text();
    int bookID = text2.toInt();
    QString text3 = ui->bookName->text();
    QString text4 = ui->bookAuthor->text();
    QString text5 = ui->bookLanguage->text();
    QDate text6 = ui->bookYear->date();
    int year = text6.year();
    QDate text7 = ui->dateEdit->date();
    if (text1.isEmpty() || text2.isEmpty() || text3.isEmpty() || text4.isEmpty() || text5.isEmpty()) {
        ui->label_7->setText("Не все поля заполнены.");
    } else {
        Book book(bookID,text3,text4,text5,year,text7);
        for (int i = 0; i < 1000; i++) {
            if (readers[i].getID() == id) {
                readers[i].addBorrowedBook(book);
                this->close();
                return;
            }
        }
        ui->label_7->setText("Читатель не был найден.");
    }
}

void addBooks::on_pushButton_clicked() {
    this->close();
}


//void MainWindow::on_add_clicked()
//{
//    for (const Book& book : books) {
//        QListWidgetItem* item = new QListWidgetItem(book.name);
//        item->setData(Qt::UserRole, QVariant::fromValue(book));
//        ui->listWidget_2->addItem(item);
//    }
//}


void MainWindow::on_pushButton_2_clicked() {
    findName *bebrochka = new findName(this);
    bebrochka->show();
}



void MainWindow::on_comboBox_currentIndexChanged(int index) {
    int id = readers[index].getID();
    QString address = readers[index].getAddress();
    QString number = readers[index].getNumber();
    ui->addr->setText(address);
    ui->phone->setText(number);
    ui->id->setText(QString::number(id));
    QList<Book> list = readers[index].getBorrowedBooks();
    for (int i = 0; i < list.size(); i++) {
        ui->listWidget->clear();
        QListWidgetItem *item = new QListWidgetItem(list[i].name);
        ui->listWidget->addItem(item);
    }
}

