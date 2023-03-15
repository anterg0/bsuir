#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "booklist.cpp"
#include <QMessageBox>
#include "adddialog.h"
#include "insertdialog.h"
#include <QDir>
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include "bookinfo.h"

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


void MainWindow::on_add_clicked()
{
    addDialog *bruh = new addDialog(this);
    connect(bruh, &addDialog::addBook, this, &MainWindow::addBook);
    bruh->exec();
}

void MainWindow::addBook(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount) {
    for (int i = 0; i < bebra.capacity(); i++) {
        if (bebra.getID(i) == bookID) {
            QMessageBox::critical(this, "Error", "ID must be unique.");
            return;
        }
    }
    Node* newNode = new Node();
    newNode->bookID = bookID;
    newNode->bookName = bookName;
    newNode->bookAuthor = bookAuthor;
    newNode->bookPublisher = bookPublisher;
    newNode->bookYear = bookYear;
    newNode->bookPageAmount = bookPageAmount;
    bebra.add(newNode);
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();
    ui->tableWidget->insertRow(rows);
    for (int i = 0; i <= cols;i++) {
        for (int j = 0; j <= rows; j++) {
            if (i == 0) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getID(j)));
                ui->tableWidget->setItem(j,0,item);
            }
            if (i == 1) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getName(j));
                ui->tableWidget->setItem(j,1,item);
            }
            if (i == 2) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getAuthor(j));
                ui->tableWidget->setItem(j,2,item);
            }
            if (i == 3) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getPublisher(j));
                ui->tableWidget->setItem(j,3,item);
            }
            if (i == 4) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getYear(j)));
                ui->tableWidget->setItem(j,4,item);
            }
            if (i == 5) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getPages(j)));
                ui->tableWidget->setItem(j,5,item);
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
    if (!fileName.isEmpty()) {
        std::ofstream file(fileName.toStdString(), std::ios::app);
        file << '\n' + std::to_string(bebra.getID(bebra.capacity() - 1)) + '\n';
        file << bebra.getName(bebra.capacity() - 1).toStdString() + '\n';
        file << bebra.getAuthor(bebra.capacity() - 1).toStdString() + '\n';
        file << bebra.getPublisher(bebra.capacity() - 1).toStdString() + '\n';
        file << std::to_string(bebra.getYear(bebra.capacity() - 1)) + '\n';
        file << std::to_string(bebra.getPages(bebra.capacity() - 1));
        file.close();
        ui->statusbar->showMessage("File auto-saved.", 3000);
    }
}


void MainWindow::on_del_clicked()
{
    int index = ui->delIndex->text().toInt() - 1;
    if (bebra.del(index)) {
        ui->tableWidget->removeRow(index);
        ui->delIndex->clear();
        QMessageBox::information(this, "Deletion", "Deleted successfully.");
        if (!fileName.isEmpty()) {
            std::ofstream file(fileName.toStdString(), std::ios::trunc);
            for (int i = 0; i < bebra.capacity(); i++) {
                file << std::to_string(bebra.getID(i)) + '\n';
                file << bebra.getName(i).toStdString() + '\n';
                file << bebra.getAuthor(i).toStdString() + '\n';
                file << bebra.getPublisher(i).toStdString() + '\n';
                file << std::to_string(bebra.getYear(i)) + '\n';
                if (i != bebra.capacity() - 1) file << std::to_string(bebra.getPages(i)) + '\n';
                else file << std::to_string(bebra.getPages(i));
            }
            file.close();
            ui->statusbar->showMessage("File auto-saved.", 3000);
        }
    } else {
        QMessageBox::critical(this, "Deletion", "Error");
    }
}


void MainWindow::on_pushButton_clicked()
{
    bebra.debug();
}


void MainWindow::on_ins_clicked()
{
    insertDialog *dialog = new insertDialog(this);
    connect(dialog, &insertDialog::addBook, this, &MainWindow::insertBook);
    dialog->exec();
}

void MainWindow::insertBook(int index,int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount) {
    for (int i = 0; i < bebra.capacity(); i++) {
        if (bebra.getID(i) == bookID) {
            QMessageBox::critical(this, "Error", "ID must be unique.");
            return;
        }
    }
    Node* newNode = new Node();

    newNode->bookID = bookID;
    newNode->bookName = bookName;
    newNode->bookAuthor = bookAuthor;
    newNode->bookPublisher = bookPublisher;
    newNode->bookYear = bookYear;
    newNode->bookPageAmount = bookPageAmount;
    bebra.ins(newNode, index);
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();
    ui->tableWidget->insertRow(rows);
    for (int i = 0; i <= cols;i++) {
        for (int j = 0; j <= rows; j++) {
            if (i == 0) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getID(j)));
                ui->tableWidget->setItem(j,0,item);
            }
            if (i == 1) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getName(j));
                ui->tableWidget->setItem(j,1,item);
            }
            if (i == 2) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getAuthor(j));
                ui->tableWidget->setItem(j,2,item);
            }
            if (i == 3) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getPublisher(j));
                ui->tableWidget->setItem(j,3,item);
            }
            if (i == 4) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getYear(j)));
                ui->tableWidget->setItem(j,4,item);
            }
            if (i == 5) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getPages(j)));
                ui->tableWidget->setItem(j,5,item);
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
    if (!fileName.isEmpty()) {
        std::ofstream file(fileName.toStdString(), std::ios::trunc);
        for (int i = 0; i < bebra.capacity(); i++) {
            file << std::to_string(bebra.getID(i)) + '\n';
            file << bebra.getName(i).toStdString() + '\n';
            file << bebra.getAuthor(i).toStdString() + '\n';
            file << bebra.getPublisher(i).toStdString() + '\n';
            file << std::to_string(bebra.getYear(i)) + '\n';
            if (i != bebra.capacity() - 1) file << std::to_string(bebra.getPages(i)) + '\n';
            else file << std::to_string(bebra.getPages(i));
        }
        file.close();
        ui->statusbar->showMessage("File auto-saved.", 3000);
    }
}

void MainWindow::on_edit_clicked()
{
    addDialog *bruh = new addDialog(this);
    connect(bruh, &addDialog::addBook, this, &MainWindow::changeBook);
    int currentRow = ui->tableWidget->currentRow();
    qDebug() << currentRow;
    if (currentRow == -1) {
        if (ui->tableWidget->rowCount() == 0) {
            QMessageBox::warning(this, "Bruh", "What are you even trying to do? You don't have anything in your table.");
            return;
        }
        QMessageBox::warning(this, "Error", "Select any row by pressing any column on that row.");
        return;
    }
    connect(this, &MainWindow::getEdit, bruh, &addDialog::setEdit);
    Node* beb = bebra.getNode(currentRow);
    emit getEdit(beb->bookID,beb->bookName,beb->bookAuthor,beb->bookPublisher,beb->bookYear,beb->bookPageAmount);
    bruh->exec();
}

void MainWindow::changeBook(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount) {
    for (int i = 0; i < bebra.capacity(); i++) {
        if (bebra.getID(ui->tableWidget->currentRow()) == bookID) break;
        if (bebra.getID(i) == bookID) {
            QMessageBox::critical(this, "Error", "ID must be unique.");
            return;
        }
    }
    int currentRow = ui->tableWidget->currentRow();
    Node* newNode = new Node();
    newNode->bookID = bookID;
    newNode->bookName = bookName;
    newNode->bookAuthor = bookAuthor;
    newNode->bookPublisher = bookPublisher;
    newNode->bookYear = bookYear;
    newNode->bookPageAmount = bookPageAmount;
    bebra.del(currentRow);
    bebra.ins(newNode, currentRow);
//    int index = currentRow + 1;
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getID(currentRow)));
            ui->tableWidget->setItem(currentRow,0,item);
        }
        if (i == 1) {
            QTableWidgetItem *item = new QTableWidgetItem(bebra.getName(currentRow));
            ui->tableWidget->setItem(currentRow,1,item);
        }
        if (i == 2) {
            QTableWidgetItem *item = new QTableWidgetItem(bebra.getAuthor(currentRow));
            ui->tableWidget->setItem(currentRow,2,item);
        }
        if (i == 3) {
            QTableWidgetItem *item = new QTableWidgetItem(bebra.getPublisher(currentRow));
            ui->tableWidget->setItem(currentRow,3,item);
        }
        if (i == 4) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getYear(currentRow)));
            ui->tableWidget->setItem(currentRow,4,item);
        }
        if (i == 5) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getPages(currentRow)));
            ui->tableWidget->setItem(currentRow,5,item);
        }
    }
    if (!fileName.isEmpty()) {
        std::ofstream file(fileName.toStdString(), std::ios::trunc);
        for (int i = 0; i < bebra.capacity(); i++) {
            file << std::to_string(bebra.getID(i)) + '\n';
            file << bebra.getName(i).toStdString() + '\n';
            file << bebra.getAuthor(i).toStdString() + '\n';
            file << bebra.getPublisher(i).toStdString() + '\n';
            file << std::to_string(bebra.getYear(i)) + '\n';
            if (i != bebra.capacity() - 1) file << std::to_string(bebra.getPages(i)) + '\n';
            else file << std::to_string(bebra.getPages(i));
        }
        file.close();
        ui->statusbar->showMessage("File auto-saved.", 3000);
    }
}


void MainWindow::on_actionOpen_File_triggered()
{
    bebra.clear();
    QString check = fileName;
    QFileDialog dialog;
    fileName = dialog.getOpenFileName(this,nullptr,QDir::homePath(),tr("Text files (*.txt)"));
    std::ifstream file;
    file.open(fileName.toStdString());
    std::ifstream fileCheck;
    fileCheck.open(fileName.toStdString());
    fileCheck.seekg(0,std::ios::end);
    size_t size = fileCheck.tellg();
    if (size == 0) {
        if (check.isEmpty()) fileName = "";
        else fileName = check;
        QMessageBox::warning(this, "Error", "File is empty.");
        return;
    }
    fileCheck.close();
    if (file.is_open()) {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
    } else return;
    std::string line;
    while (std::getline(file, line)) {
        Node *book = new Node();
        QString check = QString::fromStdString(line);
        for (int i = 0; i < check.length(); i++) {
            if (!check.at(i).isDigit()) {
                QMessageBox::critical(this, "Error", "Incorrect file format.");
                return;
            }
        }
        book->bookID = std::stoi(line);
        std::getline(file, line);
        book->bookName = QString::fromStdString(line);
        std::getline(file, line);
        book->bookAuthor = QString::fromStdString(line);
        std::getline(file, line);
        book->bookPublisher = QString::fromStdString(line);
        std::getline(file, line);
        check = QString::fromStdString(line);
        for (int i = 0; i < check.length(); i++) {
            if (!check.at(i).isDigit()) {
                QMessageBox::critical(this, "Error", "Incorrect file format.");
                return;
            }
        }
        book->bookYear = std::stoi(line);
        std::getline(file, line);
        check = QString::fromStdString(line);
        for (int i = 0; i < check.length(); i++) {
            if (!check.at(i).isDigit()) {
                QMessageBox::critical(this, "Error", "Incorrect file format.");
                return;
            }
        }
        book->bookPageAmount = std::stoi(line);
        bebra.add(book);
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        int index = row;
        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getID(index)));
                ui->tableWidget->setItem(row,0,item);
            }
            if (i == 1) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getName(index));
                ui->tableWidget->setItem(row,1,item);
            }
            if (i == 2) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getAuthor(index));
                ui->tableWidget->setItem(row,2,item);
            }
            if (i == 3) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getPublisher(index));
                ui->tableWidget->setItem(row,3,item);
            }
            if (i == 4) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getYear(index)));
                ui->tableWidget->setItem(row,4,item);
            }
            if (i == 5) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getPages(index)));
                ui->tableWidget->setItem(row,5,item);
            }
        }
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
}


void MainWindow::on_actionSave_File_triggered()
{
    if (fileName.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::homePath(), tr("Text files (*.txt)"));
        if (fileName.isEmpty()) {
            return;
        }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unknown error. File couldn't be saved.");
            return;
        }
        QTextStream out(&file);
        for (int i = 0; i < ui->tableWidget->rowCount();i++) {
            out << QString::number(bebra.getID(i)) + '\n' + bebra.getName(i) + '\n' + bebra.getAuthor(i) + '\n' + bebra.getPublisher(i) + '\n' + QString::number(bebra.getYear(i)) + '\n' + QString::number(bebra.getPages(i));
            if (i != ui->tableWidget->rowCount() - 1) out << '\n';
            else continue;
        }
        file.close();
        QMessageBox::information(this, "Save", "File saved.");
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&file);
        for (int i = 0; i < ui->tableWidget->rowCount();i++) {
            out << QString::number(bebra.getID(i)) + '\n' + bebra.getName(i) + '\n' + bebra.getAuthor(i) + '\n' + bebra.getPublisher(i) + '\n' + QString::number(bebra.getYear(i)) + '\n' + QString::number(bebra.getPages(i));
            if (i != ui->tableWidget->rowCount() - 1) out << '\n';
            else continue;
        }
        file.close();
        QMessageBox::information(this, "Save", "File saved.");
    }
}


void MainWindow::on_actionClose_File_triggered()
{
    if (!fileName.isEmpty()) {
        this->on_actionSave_File_triggered();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        fileName.clear();
    } else QMessageBox::critical(this, "File", "File isn't open.");
}


void MainWindow::on_pushButton_2_clicked()
{
    QString check = ui->findID->text();
    if (check.isEmpty()) {
        QMessageBox::warning(this, "Error", "Enter a number.");
        return;
    }
    for (int i = 0; i < check.length(); i++) {
        if (!check.at(i).isDigit()) {
            QMessageBox::warning(this, "Error", "ID must be a number.");
            return;
        }
    }
    int bookID = ui->findID->text().toInt();
    bookInfo *info = new bookInfo(this);
    Node* found = bebra.getHp();
    if (found == NULL) {
        QMessageBox::warning(this, "Error", "That bookID doesn't exist.");
        return;
    }
    while (bookID != found->bookID) {
        found = found->next;
        if (found == NULL) {
            QMessageBox::warning(this, "Error", "That bookID doesn't exist.");
            return;
        }
    }
    connect(this, &MainWindow::getInfo, info, &bookInfo::enterInfo);
    emit getInfo(found->bookID, found->bookName, found->bookAuthor, found->bookPublisher, found->bookYear, found->bookPageAmount);
    info->exec();
}


void MainWindow::on_search_textChanged(const QString &arg1)
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
            QTableWidgetItem *item = ui->tableWidget->item(row, 2);  // assuming author name is in column 2
            if (item->text().contains(arg1  , Qt::CaseInsensitive)) {
                // show the matching row
                ui->tableWidget->showRow(row);
            } else {
                // hide the non-matching row
                ui->tableWidget->hideRow(row);
            }
        }

}


void MainWindow::on_pushButton_3_clicked()
{
    QString name = ui->searchName->text();
        int year = ui->searchYear->text().toInt();

        int count = 0;
        QString message;

        for (int i = 0; i < bebra.capacity(); i++) {
            Node* book = bebra.getNode(i);
            if (book->bookName == name && book->bookYear == year) {
                message += "Book ID: " + QString::number(book->bookID) + "\n";
                message += "Book Name: " + book->bookName + "\n";
                message += "Book Author: " + book->bookAuthor + "\n";
                message += "Book Publisher: " + book->bookPublisher + "\n";
                message += "Book Year: " + QString::number(book->bookYear) + "\n";
                message += "Book Page Amount: " + QString::number(book->bookPageAmount) + "\n\n";
                count++;
            }
        }

        if (count > 0) {
            message += "Total Books Found: " + QString::number(count);
            QMessageBox::information(this, "Search Results", message);
        } else {
            QMessageBox::information(this, "Search Results", "No books were found.");
        }
}

bool compareByName(Node* a, Node* b) {
    return a->bookName < b->bookName;
}

bool compareByID(Node* a, Node* b) {
    return a->bookID < b->bookID;
}

bool compareByAuthor(Node* a, Node* b) {
    return a->bookAuthor < b->bookAuthor;
}

bool compareByPublisher(Node* a, Node* b) {
    return a->bookPublisher < b->bookPublisher;
}

bool compareByYear(Node* a, Node* b) {
    return a->bookYear < b->bookYear;
}

bool compareByPages(Node* a, Node* b) {
    return a->bookPageAmount < b->bookPageAmount;
}


void MainWindow::on_sortButton_clicked()
{
    if (bebra.capacity() == 0) return;
    if (ui->sortOption->currentIndex() == 0) {
        bebra.Sort(&bebra.head, compareByID);
    }
    if (ui->sortOption->currentIndex() == 1) {
        bebra.Sort(&bebra.head, compareByName);
    }
    if (ui->sortOption->currentIndex() == 2) {
        bebra.Sort(&bebra.head, compareByAuthor);
    }
    if (ui->sortOption->currentIndex() == 3) {
        bebra.Sort(&bebra.head, compareByPublisher);
    }
    if (ui->sortOption->currentIndex() == 4) {
        bebra.Sort(&bebra.head, compareByYear);
    }
    if (ui->sortOption->currentIndex() == 5) {
        bebra.Sort(&bebra.head, compareByPages);
    }
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();
    for (int i = 0; i <= cols;i++) {
        for (int j = 0; j < rows; j++) {
            if (i == 0) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getID(j)));
                ui->tableWidget->setItem(j,0,item);
            }
            if (i == 1) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getName(j));
                ui->tableWidget->setItem(j,1,item);
            }
            if (i == 2) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getAuthor(j));
                ui->tableWidget->setItem(j,2,item);
            }
            if (i == 3) {
                QTableWidgetItem *item = new QTableWidgetItem(bebra.getPublisher(j));
                ui->tableWidget->setItem(j,3,item);
            }
            if (i == 4) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getYear(j)));
                ui->tableWidget->setItem(j,4,item);
            }
            if (i == 5) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(bebra.getPages(j)));
                ui->tableWidget->setItem(j,5,item);
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
    if (!fileName.isEmpty()) {
        std::ofstream file(fileName.toStdString(), std::ios::trunc);
        for (int i = 0; i < bebra.capacity(); i++) {
            file << std::to_string(bebra.getID(i)) + '\n';
            file << bebra.getName(i).toStdString() + '\n';
            file << bebra.getAuthor(i).toStdString() + '\n';
            file << bebra.getPublisher(i).toStdString() + '\n';
            file << std::to_string(bebra.getYear(i)) + '\n';
            if (i != bebra.capacity() - 1) file << std::to_string(bebra.getPages(i)) + '\n';
            else file << std::to_string(bebra.getPages(i));
        }
        file.close();
        ui->statusbar->showMessage("File auto-saved.", 3000);
    }
}
