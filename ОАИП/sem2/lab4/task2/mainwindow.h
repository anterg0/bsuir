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
    void Refresh();

private slots:
    void on_changeString1_clicked();

    void on_changeString2_clicked();

    void on_strncpyString1_clicked();

    void on_strncpyString2_clicked();

    void on_strcatString1_clicked();

    void on_strcatString2_clicked();

    void on_pushButton_clicked();

    void on_strncatString1_clicked();

    void on_strncatString2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
