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
    void UpdateSetTable();
    void UpdateMapTable();

private slots:
    void on_addSet_clicked();

    void on_delSet_clicked();

    void on_findSet_clicked();

    void on_outputSet_clicked();

    void on_clearSet_clicked();

    void on_addMap_clicked();

    void on_delMap_clicked();

    void on_findMap_clicked();

    void on_outputMap_clicked();

    void on_clearMap_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
