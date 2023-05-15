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

    QString getText();

    QString Struct(QString line);

    QString Vars(QString line);

    QString LocalVars(QString line);

    QString Overrides(QString line);

    QString Proto(QString line);

    QString Depth(QString line);

    QString Changes(QString line);

    QString Errors(QString line);

private slots:
    void on_actionOpen_File_triggered();

    void on_pStructs_clicked();

    void on_pVar_clicked();

    void on_pLocVar_clicked();

    void on_pOver_clicked();

    void on_pProt_clicked();

    void on_pDep_clicked();

    void on_pVarChan_clicked();

    void on_pErr_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
