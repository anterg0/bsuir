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
    void printVectors();

private slots:
    void on_v1Push_clicked();

    void on_swapVec_clicked();

    void on_v2Push_clicked();

    void on_v1Pop_clicked();

    void on_v2Pop_clicked();

    void on_v1Clear_clicked();

    void on_v2Clear_clicked();

    void on_v1Resize_clicked();

    void on_v2Resize_clicked();

    void on_v1At_clicked();

    void on_v2At_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
