#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();

    void on_pushButton_clicked();

    void on_SearchButton_clicked();

    void on_ModuloButton_clicked();

    void on_SearchLine_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
