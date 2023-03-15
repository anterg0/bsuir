    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include "stack.h"
    #include <QMessageBox>
    #include <QTextBlock>

    stack bebra(1000);

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }


    void MainWindow::on_pushButton_clicked()
    {
        QTextDocument *doc = ui->plainTextEdit->document();
        for (int i = 0; i < doc->blockCount(); i++) {
            QTextBlock block = doc->findBlockByNumber(i);
            QString line = block.text().trimmed();
            for (int j = 0; j < line.length(); j++) {
                if (line.at(j) == '{' || line.at(j) == '[' || line.at(j) == '(') {
                    bebra.push(line.at(j), i + 1, j + 1);
                    continue;
                }
                if (bebra.getTop() != NULL) {
                    if (bebra.getTop()->bracket == '{') {
                        if (line.at(j) == '}') {
                            bebra.pop();
                            continue;
                        }
                        else if (line.at(j) == ')' || line.at(j) == ']') {
                            QString message = "Houston, we have a problem at line ";
                            message += QString::number(i + 1);
                            message += " and column ";
                            message += QString::number(j + 1);
                            QMessageBox::critical(this, "Bruh", message);
                            bebra.clear();
                            return;
                        }
                    }
                    if (bebra.getTop()->bracket == '(') {
                        if (line.at(j) == ')') {
                            bebra.clear();
                            continue;
                        }
                        else if (line.at(j) == '}' || line.at(j) == ']') {
                            QString message = "Houston, we have a problem at line ";
                            message += QString::number(i + 1);
                            message += " and column ";
                            message += QString::number(j + 1);
                            QMessageBox::critical(this, "Bruh", message);
                            bebra.clear();
                            return;
                        }
                    }
                    if (bebra.getTop()->bracket == '[') {
                        if (line.at(j) == ']') {
                            bebra.pop();
                            continue;
                        }
                        else if (line.at(j) == ')' || line.at(j) == '}') {
                            QString message = "Houston, we have a problem at line ";
                            message += QString::number(i + 1);
                            message += " and column ";
                            message += QString::number(j + 1);
                            QMessageBox::critical(this, "Bruh", message);
                            bebra.clear();
                            return;
                        }
                    }
                }
                if (bebra.isEmpty() && (line.at(j) == ')' || line.at(j) == ']' || line.at(j) == '}')) {
                    QString message = "Houston, we have a problem at line ";
                    message += QString::number(i + 1);
                    message += " and column ";
                    message += QString::number(j + 1);
                    QMessageBox::critical(this, "Bruh", message);
                    bebra.clear();
                    return;
                }
            }
        }
        if (!bebra.isEmpty()) {
            QString message = "Houston, we have an unclosed problem at line ";
            message += QString::number(bebra.getTop()->line);
            message += " and column ";
            message += QString::number(bebra.getTop()->column);
            QMessageBox::critical(this, "Bruh", message);
            bebra.clear();
            return;
        }
        QMessageBox::information(this, "Nice job mate!", "Congrats! I couldn't find any missing/wrong brackets in your text.");

    }
