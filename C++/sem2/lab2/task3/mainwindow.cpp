#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"
#include "stackdouble.h"
#include <QStack>
#include <QMessageBox>

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

bool MainWindow::isOperator(QChar c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int MainWindow::getPriority(QChar c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

std::string MainWindow::infixToPostfix(std::string infix) {
    stack s(1000);
    std::string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!s.empty() && s.top()->letter != '(') {
                postfix += s.top()->letter.toLatin1();
                s.pop();
            }
            s.pop();
        }
        else if (!isOperator(infix[i])) {
            postfix += infix[i];
        }
        else {
            while (!s.empty() && getPriority(s.top()->letter) >= getPriority(infix[i])) {
                postfix += s.top()->letter.toLatin1();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) {
        postfix += s.top()->letter.toLatin1();
        s.pop();
    }
    return postfix;
}

std::string MainWindow::addSpacesToInfix(std::string infix) {
    std::string result;
    for (int i = 0; i < infix.length();i++) {
        if (infix[i] == ' ' || isdigit(infix[i]) || infix[i] == '.') {
            result += infix[i];
        } else {
            result += ' ';
            result += infix[i];
            result += ' ';
        }
    }
    return result;
}

std::string MainWindow::addSpacesToPostfix(std::string postfix) {
    std::string result;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ' && postfix[i + 1] == ' ') {
            postfix.erase(i,1);
        } else if (postfix[i] == ' ' && i == postfix.length() - 1) {
            postfix.erase(i,1);
        }
    }
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ' || isdigit(postfix[i]) || postfix[i] == '.') {
            result += postfix[i];
        }
        else {
            result += ' ';
            result += postfix[i];
            result += ' ';
        }
    }
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == ' ' && result[i + 1] == ' ') {
            result.erase(i,1);
        } else if (result[i] == ' ' && i == result.length() - 1) {
            result.erase(i,1);
        }
    }
    return result;
}

double evaluatePostfix(QString postfix) {
    stackDouble stack(1000);

    QStringList tokens = postfix.split(" ");
    foreach(QString token, tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            double op2 = stack.pop();
            double op1 = stack.pop();

            if (token == "+") {
                stack.push(op1 + op2);
            } else if (token == "-") {
                stack.push(op1 - op2);
            } else if (token == "*") {
                stack.push(op1 * op2);
            } else if (token == "/") {
                stack.push(op1 / op2);
            } else if (token == "^") {
                stack.push(pow(op1, op2));
            }
        } else if (token == "") {
            continue;
        } else {
            stack.push(token.toDouble());
        }
    }
    return stack.pop();
}


void MainWindow::on_pushButton_clicked()
{
    bool isntSolvable = false;
    bool stringIsSpaces = false;
    bool OperatorExists = false;
    if (ui->lineEdit->text().length() > 255) {
        QMessageBox::warning(this,"Error", "Expression is too long (more than 255 symbols).");
        return;
    }
    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox::warning(this,"Error","You didn't enter anything.");
        return;
    }
    std::string bebra = ui->lineEdit->text().toStdString();
    for (int i = 0; i < bebra.length(); i++) {
        if (bebra[i] != ' ') {
            stringIsSpaces = false;
            break;
        }
        else {
            stringIsSpaces = true;
        }
    }
    for (int i = 0; i < bebra.length(); i++) {
        if (isOperator(bebra[i])) {
            OperatorExists = true;
            break;
        }
    }
    if (stringIsSpaces) {
        QMessageBox::warning(this,"Error","Your expression contains only spaces.");
        return;
    }
    QTableWidgetItem *item = new QTableWidgetItem(ui->lineEdit->text());
    int row = ui->infixWidget->rowCount();
    ui->infixWidget->insertRow(row);
    ui->infixWidget->setItem(row,0,item);
    std::string infix = ui->lineEdit->text().toStdString();
    infix = addSpacesToInfix(infix);
    std::string postfix = infixToPostfix(infix);
    postfix = addSpacesToPostfix(postfix);
    for (int i = 0; i < postfix.length(); i++) {
        if (isalpha(postfix[i])) {
            isntSolvable = true;
            break;
        }
    }
    if (!isntSolvable) {
        if (OperatorExists) {
            double bebra = evaluatePostfix(QString::fromStdString(postfix));
            postfix += " = ";
            postfix += std::to_string(bebra);
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(postfix));
            int row = ui->postfixWidget->rowCount();
            ui->postfixWidget->insertRow(row);
            ui->postfixWidget->setItem(row,0,item);
        } else {
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(postfix));
            int row = ui->postfixWidget->rowCount();
            ui->postfixWidget->insertRow(row);
            ui->postfixWidget->setItem(row,0,item);
        }
    } else {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(postfix));
        int row = ui->postfixWidget->rowCount();
        ui->postfixWidget->insertRow(row);
        ui->postfixWidget->setItem(row,0,item);
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

