#ifndef FINDNAME_H
#define FINDNAME_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class findName;
}

class findName : public QDialog
{
    Q_OBJECT

public:
    explicit findName(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~findName();

private slots:

    void on_pushButton_clicked();

private:
    Ui::findName *ui;
    MainWindow *m_mainWindow;
};

#endif // FINDNAME_H
