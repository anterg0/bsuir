#ifndef ADDBOOKS_H
#define ADDBOOKS_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class addBooks;
}

class addBooks : public QDialog
{
    Q_OBJECT

public:
    explicit addBooks(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~addBooks();
    Ui::addBooks *ui;
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    MainWindow *m_mainWindow;
};

#endif // ADDBOOKS_H
