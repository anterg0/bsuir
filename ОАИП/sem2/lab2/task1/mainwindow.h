#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "booklist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void getInfo(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);
    void getEdit(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);
private slots:
    void addBook(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);

    void changeBook(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);

    void insertBook(int index, int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);

    void on_add_clicked();

    void on_del_clicked();

    void on_pushButton_clicked();

    void on_ins_clicked();

    void on_edit_clicked();

    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionClose_File_triggered();

    void on_pushButton_2_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    BookList bebra;
    QString fileName;
};
#endif // MAINWINDOW_H
