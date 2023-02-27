#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
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
    QComboBox* getComboBox();
    QListWidget* getListWidget();
private slots:

    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_addBook_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_addReader_clicked();

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_Debters_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
