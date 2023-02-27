#ifndef CHANGEREADER_H
#define CHANGEREADER_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class changeReader;
}

class changeReader : public QDialog
{
    Q_OBJECT

public:
    Ui::changeReader *ui;
    explicit changeReader(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~changeReader();

private slots:
    void on_pushButton_clicked();

private:
    MainWindow *m_mainWindow;
};

#endif // CHANGEREADER_H
