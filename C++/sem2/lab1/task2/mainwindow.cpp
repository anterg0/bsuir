#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reader.h"
#include "addbooks.h"
#include "ui_addbooks.h"
#include "findname.h"
#include "ui_findname.h"
#include "changereader.h"
#include "ui_changereader.h"
#include "bookinfo.h"
#include "ui_bookinfo.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QRandomGenerator>
#include <QFile>
#include <QFileDialog>
#include <QRegularExpression>

QList<Reader> readers;
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

QListWidget* MainWindow::getListWidget() {
    return ui->listWidget_2;
}


MainWindow::~MainWindow()
{
    delete ui;
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
        readers.append(Reader(id, fullName, phoneNumber, contactAddress));
        ui->comboBox->addItem(readers[count].getName());
    }
    file.close();

}


void MainWindow::on_comboBox_activated(int index) {
    if (ui->comboBox->count() > 0) {
        int id = readers[index].getID();
        QString address = readers[index].getAddress();
        QString number = readers[index].getNumber();
        ui->addr->setText(address);
        ui->phone->setText(number);
        ui->id->setText(QString::number(id));
        QList<Book> list = readers[index].getBorrowedBooks();
        ui->listWidget->clear();
        for (int i = 0; i < list.size(); i++) {
            QListWidgetItem *item = new QListWidgetItem(list[i].name);
            ui->listWidget->addItem(item);
        }
    }
}


void MainWindow::on_addBook_clicked()  {
    addBooks *newWindow = new addBooks(this);
    newWindow->ui->editButton->hide();
    newWindow->show();
}

void addBooks::on_pushButton_2_clicked() {
    QRegularExpression re("\\d*");
    QListWidget *list = m_mainWindow->getListWidget();
    QString text2 = ui->bookID->text();
    for (int i = 0; i < text2.length(); i++) {
        if (!text2.at(i).isDigit()) {
            ui->label_7->setText("ID должен быть числом.");
            return;
        }
    }
    int bookID = text2.toInt();
    QString text3 = ui->bookName->text();
    QString text4 = ui->bookAuthor->text();
    QString text5 = ui->bookLanguage->text();
    QDate text6 = ui->bookYear->date();
    int year = text6.year();
    if (text2.isEmpty() || text3.isEmpty() || text4.isEmpty() || text5.isEmpty()) {
        ui->label_7->setText("Не все поля заполнены.");
    } else {
        Book book(bookID,text3,text4,text5,year);
        for (int i = 0; i < books.size();i++) {
            if (books[i].bookID == bookID) {
                ui->label_7->setText("ID уже существует.");
                return;
            }
        }
        books.append(book);
        QListWidgetItem *item = new QListWidgetItem(book.name);
        list->addItem(item);
        this->close();
    }
}


void addBooks::on_pushButton_clicked() {
    this->close();
}


void MainWindow::on_pushButton_2_clicked() {
    findName *bebrochka = new findName(this);
    bebrochka->show();
}



void MainWindow::on_comboBox_currentIndexChanged(int index) {
    if (ui->comboBox->count() > 0) {
        int id = readers[index].getID();
        QString address = readers[index].getAddress();
        QString number = readers[index].getNumber();
        ui->addr->setText(address);
        ui->phone->setText(number);
        ui->id->setText(QString::number(id));
        QList<Book> list = readers[index].getBorrowedBooks();
        ui->listWidget->clear();
        for (int i = 0; i < list.size(); i++) {
            QListWidgetItem *item = new QListWidgetItem(list[i].name);
            ui->listWidget->addItem(item);
        }
    } else {
        ui->id->clear();
        ui->addr->clear();
        ui->phone->clear();
    }
}


void MainWindow::on_pushButton_4_clicked() {
    QString selName = ui->comboBox->currentText();
    int remove = -1;
    for (int i = 0; i < readers.size(); i++) {
        if (selName == readers[i].getName()) {
            remove = i;
            break;
        }
    }
    if (remove != -1) {
        readers.removeAt(remove);
        ui->comboBox->removeItem(remove);
        for (int i = remove; i < readers.size(); i++) {
            ui->comboBox->setItemText(i, readers[i].getName());
        }
    }
}



void MainWindow::on_pushButton_3_clicked()  {
    changeReader *bruh = new changeReader(this);
    bruh->ui->id->setReadOnly(true);
    bruh->ui->name->setText(ui->comboBox->currentText());
    bruh->ui->address->setText(ui->addr->text());
    bruh->ui->phone->setText(ui->phone->text());
    bruh->show();
}

void changeReader::on_pushButton_clicked()  {
    QString text2 = ui->name->text();
    QString text3 = ui->phone->text();
    QString text4 = ui->address->text();
    QComboBox *comboBox = m_mainWindow->getComboBox();
    int sel = comboBox->currentIndex();
    if (sel == -1) return;
    readers[sel].setName(text2);
    readers[sel].setNumber(text3);
    readers[sel].setContantAddress(text4);
    comboBox->setItemText(sel,readers[sel].getName());
    this->close();
}

void MainWindow::on_addReader_clicked() {
    changeReader *bruh = new changeReader(this);
    bruh->ui->pushButton->setEnabled(false);
    bruh->ui->addButton->setEnabled(true);
    bruh->show();
}

void changeReader::on_addButton_clicked() {
    int id = ui->id->text().toInt();
    QString text2 = ui->name->text();
    QString text3 = ui->phone->text();
    QString text4 = ui->address->text();
    for (int i = 0; i < readers.size();i++) {
        if (id == readers[i].getID()) {
            ui->label->setText("ID уже существует.");
            return;
        }
    }
    readers.append(Reader(id,text2,text3,text4));
    QComboBox *comboBox = m_mainWindow->getComboBox();
    comboBox->addItem(text2);
    this->close();
}



void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item) {
    int ind = ui->listWidget_2->row(item);
    bookInfo *info = new bookInfo();
    info->ui->id->setText(QString::number(books[ind].bookID));
    info->ui->author->setText(books[ind].author);
    info->ui->name->setText(books[ind].name);
    info->ui->lan->setText(books[ind].language);
    info->ui->year->setText(QString::number(books[ind].year));
    info->show();
}


void MainWindow::on_pushButton_5_clicked()  {
    int ind = ui->listWidget_2->currentRow();
    if (ind != -1) {
        ui->listWidget_2->takeItem(ind);
        books.removeAt(ind);
        if (books.size() != 0) {
            ui->listWidget_2->clear();
            for (int i = 0; i < books.size();i++) {
                QListWidgetItem *item = new QListWidgetItem(books[i].name);
                ui->listWidget_2->addItem(item);
            }
        }
    }
}


void MainWindow::on_pushButton_6_clicked() {
    ui->label_3->clear();
    int row = ui->listWidget_2->currentRow();
    QDate date = ui->dateEdit->date();
    if (row != -1) {
        int ind = ui->comboBox->currentIndex();
        Book book = books[row];
        book.returnDate = date;
        QList<Book> list = readers[ind].getBorrowedBooks();
        for (int i = 0; i < list.size();i++) {
            if (list[i].bookID == book.bookID) {
                ui->label_3->setText("У читателя есть эта книга.");
                return;
            }
        }
        readers[ind].addBorrowedBook(book);
    }
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    int ind = ui->listWidget->row(item);
    int beb = ui->comboBox->currentIndex();
    QList<Book> boo = readers[beb].getBorrowedBooks();
    bookInfo *info = new bookInfo();
    info->ui->id->setText(QString::number(boo[ind].bookID));
    info->ui->author->setText(boo[ind].author);
    info->ui->name->setText(boo[ind].name);
    info->ui->lan->setText(boo[ind].language);
    info->ui->year->setText(QString::number(boo[ind].year));
    info->ui->date->setText(boo[ind].returnDate.toString("dd.MM.yyyy"));
    info->show();
}


void MainWindow::on_Debters_triggered() {
    QFileDialog dialog;
    QFile file(dialog.getSaveFileName(this,nullptr,QDir::homePath(),tr("Text files (*.txt)")));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening file";
        return;
    }
    QTextStream out(&file);

    for (int i = 0; i < readers.size(); i++) {
        readers[i].isDebtor();
        if (readers[i].isDebt()) {
            out << "ID: (" << readers[i].getID() << ") " << readers[i].getName() << "\t || ";
            QList<Book> list = readers[i].getBorrowedBooks();
            for (int j = 0; j < list.size();j++) {
                if (list[j].debt) out << " Book ID: (" << list[j].bookID << ") " << list[j].name;
            }
        }
        out << '\n';
    }
    file.close();
}


void MainWindow::on_bookList_triggered() {
    QFileDialog dialog;
    QFile file(dialog.getSaveFileName(this,nullptr,QDir::homePath(),tr("Text files (*.txt)")));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening file";
        return;
    }
    QTextStream out(&file);

    for (int i = 0; i < readers.size(); i++) {
        out << "ID: (" << readers[i].getID() << ") " << readers[i].getName() << ": \n";
        QList<Book> list = readers[i].getBorrowedBooks();
        for (int j = 0; j < list.size(); j++) {
            out << "ID: (" << list[j].bookID << ") " << list[j].name << "\n";
        }
    }
    file.close();
}


void MainWindow::on_pushButton_7_clicked()  {
    dialog *bebra = new dialog();
    int row = ui->listWidget->currentRow();
    int ind = ui->comboBox->currentIndex();
    if (row == -1 && ind == -1) {
        bebra->ui->label->setText("Не выбраны читатель и книга.");
        bebra->show();
        return;
    } else if (row == -1) {
        bebra->ui->label->setText("Не выбрана книга.");
        bebra->show();
        return;
    } else if (ind == -1) {
        bebra->ui->label->setText("Не выбран читатель.");
        bebra->show();
        return;
    }
    readers[ind].delBorrowedBook(row);
    ui->listWidget->clear();
    QList<Book> list = readers[ind].getBorrowedBooks();
    for (int i = 0; i < list.size();i++) {
        QListWidgetItem *item = new QListWidgetItem(list[i].name);
        ui->listWidget->addItem(item);
    }
}


void MainWindow::on_pushButton_8_clicked() {
    int check = ui->listWidget_2->currentRow();
    if (check != -1) {
        addBooks *bruh = new addBooks(this);
        bruh->ui->pushButton_2->hide();
        bruh->ui->bookID->setReadOnly(true);
        int row = ui->listWidget_2->currentRow();

        bruh->ui->bookAuthor->setText(books[row].author);
        bruh->ui->bookName->setText(books[row].name);
        bruh->ui->bookLanguage->setText(books[row].language);
        bruh->ui->bookYear->setDate(QDate(books[row].year,1,1));
        bruh->ui->editButton->setDefault(true);
        bruh->ui->pushButton_2->setDefault(false);
        bruh->show();
    }
}

void addBooks::on_editButton_clicked()  {
    QListWidget *list = m_mainWindow->getListWidget();
    int row = list->currentRow();
    QString text1 = ui->bookName->text();
    QString text2 = ui->bookAuthor->text();
    QString text3 = ui->bookLanguage->text();
    QDate date = ui->bookYear->date();
    books[row].name = text1;
    books[row].author = text2;
    books[row].language = text3;
    books[row].year = date.toString("yyyy").toInt();
    list->clear();
    for (int i = 0; i < books.size(); i++) {
        QListWidgetItem *item = new QListWidgetItem(books[i].name);
        list->addItem(item);
    }
    this->close();
}

void MainWindow::on_pushButton_9_clicked()  {
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
        if (parts.size() < 5) {
            qDebug() << "Invalid line format: " << line;
            continue;
        }
        int id = parts[0].toInt();
        QString bookAuthor = parts[1];
        QString bookLanguage = parts[2];
        int bookYear = parts[3].toInt();
        QString bookName;
        for (int i = 4; i < parts.size(); i++) bookName += parts[i] + ' ';
        bookName.erase(bookName.end() - 1,bookName.end());
        int count = ui->listWidget_2->count();
        books.append(Book(id, bookName, bookAuthor, bookLanguage, bookYear));
        ui->listWidget_2->addItem(books[count].name);
    }
    file.close();
}


void MainWindow::on_pushButton_10_clicked() {
    QFileDialog dialog;
    QFile file(dialog.getSaveFileName(this,nullptr,QDir::homePath(),tr("Text files (*.txt)")));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening file";
        return;
    }
    QTextStream out(&file);

    for (int i = 0; i < books.size(); i++) {
        out << books[i].bookID << " " << books[i].author << " " << books[i].language << " " << books[i].year << " " << books[i].name << "\n";
    }
    file.close();
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)   {
    if (ui->comboBox_2->currentIndex() == 1) {
        for (int i = 0; i < ui->listWidget_2->count(); i++) {
            QListWidgetItem *item = ui->listWidget_2->item(i);
            QString itemText = item->text();
            if (itemText.contains(arg1, Qt::CaseInsensitive)) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    } else if (ui->comboBox_2->currentIndex() == 0) {
        for (int i = 0; i < ui->listWidget_2->count(); i++) {
            QListWidgetItem *item = ui->listWidget_2->item(i);
            QString itemText = books[i].author;
            if (itemText.contains(arg1, Qt::CaseInsensitive)) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    }
}

bool compareByID (Book a, Book b) {
    return a.bookID < b.bookID;
}

bool compareByName (Book a, Book b) {
    return a.name < b.name;
}

bool compareByAuthor (Book a, Book b) {
    return a.author < b.author;
}

bool compareByLanguage (Book a, Book b) {
    return a.language < b.language;
}

bool compareByYear (Book a, Book b) {
    return a.year < b.year;
}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->comboBox_3->currentIndex() == 0) {
        std::sort(books.begin(),books.end(),compareByID);
        ui->listWidget_2->clear();
        for (int i = 0; i < books.size(); i++) {
            ui->listWidget_2->addItem(books[i].name);
        }
    }
    if (ui->comboBox_3->currentIndex() == 1) {
        std::sort(books.begin(),books.end(),compareByName);
        ui->listWidget_2->clear();
        for (int i = 0; i < books.size(); i++) {
            ui->listWidget_2->addItem(books[i].name);
        }
    }
    if (ui->comboBox_3->currentIndex() == 2) {
        std::sort(books.begin(),books.end(),compareByAuthor);
        ui->listWidget_2->clear();
        for (int i = 0; i < books.size(); i++) {
            ui->listWidget_2->addItem(books[i].name);
        }
    }
    if (ui->comboBox_3->currentIndex() == 3) {
        std::sort(books.begin(),books.end(),compareByLanguage);
        ui->listWidget_2->clear();
        for (int i = 0; i < books.size(); i++) {
            ui->listWidget_2->addItem(books[i].name);
        }
    }
    if (ui->comboBox_3->currentIndex() == 4) {
        std::sort(books.begin(),books.end(),compareByYear);
        ui->listWidget_2->clear();
        for (int i = 0; i < books.size(); i++) {
            ui->listWidget_2->addItem(books[i].name);
        }
    }
}

