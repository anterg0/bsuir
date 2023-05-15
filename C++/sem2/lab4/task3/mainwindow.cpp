#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QDebug>
#include <regex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setReadOnly(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getText(){
    QString str = ui->textBrowser->toPlainText();
    return str;
}

QString MainWindow::Struct(QString line)
{
    QStringList lineList = line.split("\n");
    QString answ;
    int classes = 0;
    int structures = 0;
    int arrays = 0;
    std::vector<std::string> stdLineList;
    for (int i = 0; i < lineList.size(); ++i){
        stdLineList.push_back(lineList[i].toStdString());
    }

    std::regex pattern(R"((class)\s+[a-zA-Z_][a-zA-Z0-9_]*[\s\S]*?\{)");
    std::cmatch result;
    for (int i = 0; i < stdLineList.size(); ++i){
        if (std::regex_search(stdLineList[i].c_str(), result, pattern)){
            classes++;
        }
    }

    pattern = R"((struct)\s+[a-zA-Z_][a-zA-Z0-9_]*[\s\S]*?\{)";
    for (int i = 0; i < stdLineList.size(); ++i){
        if (std::regex_search(stdLineList[i].c_str(), result, pattern)){
            structures++;
        }
    }


    pattern = R"(\w+\s+\w+\s*\[\s*\d+\s*\](\s*=\s*\{)?)";
    for (int i = 0; i < stdLineList.size(); ++i){
        if (std::regex_search(stdLineList[i].c_str(), result, pattern)){
            arrays++;
        }
    }
    if (classes == 0 && structures == 0 && arrays == 0) {
        return "Nothing was found.";
    }
    answ = "Number of classes: " + QString::number(classes) + "\nNumber of structs: " + QString::number(structures) + "\nNumber of arrays: " + QString::number(arrays);
    return answ;
}

QString MainWindow::Vars(QString line)
{
    QString answ;
    std::string input = line.toStdString();
    std::unordered_map<std::string, int> types;
    std::regex pattern("\\b(?!(struct|class|void|namespace|return)\\s)(\\w+)((\\s+)|(\\s*(\\*)\\s*))(\\w+)\\s*(=\\s*(\\S+))?\\s*(,\\s*\\w+\\s*(=\\s*(\\S+))?)*\;");
    std::sregex_iterator next(input.begin(), input.end(), pattern);
    std::sregex_iterator end;
    while (next != end){
        std::smatch match = *next;
        int index = next->position();
        answ += "line " + QString::number(std::count(input.begin(), input.begin() + index, '\n') + 1) + ": " + QString::fromStdString(match[0].str()) + "\n";
        std::string typeName = match[2].str();
        std::string matchstr = match[0].str();
        int amount = std::count(matchstr.begin(), matchstr.end(), ',');
        if (types.find(typeName) == types.end()) {
            types[typeName] = 1 + amount;
        }
        else {
            types[typeName] += 1 + amount;
        }
        ++next;
    }
    if (types.empty()) {
        answ += "No variables found.\n";
    }
    answ += "\n";
    for (auto it = types.begin(); it != types.end(); ++it) {
        std::string typeName = it->first;
        int num_overloads = it->second;
        answ += "Variable of the type " + QString::fromStdString(typeName) + ": " + QString::number(num_overloads) + "\n";
    }
    return answ;
}

QString MainWindow::Overrides(QString line)
{
    QString answ;
    std::string input = line.toStdString();
    std::regex pattern2(R"(^\s*(?!template)(?!typedef)\w+\s+\w+\(.*\)\s*(const)?\s*(volatile)?\s*(override)?\s*(final)?\s*(=\s*0)?\s*;)");
    std::regex pattern("([\\w\\*]+)\\s+(\\w+)\\((.*?)\\)(\\;|\\{)");

    std::unordered_map<std::string, int> function_map;

    std::sregex_iterator next(input.begin(), input.end(), pattern);
    std::sregex_iterator end;
    while (next != end){
        std::smatch match = *next;
        std::string function_name = match[2];

        if (function_map.find(function_name) == function_map.end()) {
            function_map[function_name] = 1;
        }
        else {
            function_map[function_name]++;
        }
        ++next;
    }

    bool found_overloaded_functions = false;
    for (auto it = function_map.begin(); it != function_map.end(); ++it) {
        std::string function_name = it->first;
        int num_overloads = it->second;
        if (num_overloads > 1) {
            answ += QString::fromStdString("Function " + function_name + " has ") + QString::number(num_overloads) + QString::fromStdString(" override(-s)\n");
            found_overloaded_functions = true;
        }
    }

    if (!found_overloaded_functions) {
        answ = QString::fromStdString("No overrides found.");
    }
    return answ;
}

QString MainWindow::Proto(QString line)
{
    QString answ;
    std::regex pattern("([\\w\\*]+)\\s+(\\w+)\\((.*?)\\)(\\;|\\{)");
    std::string input = line.toStdString();
    std::sregex_iterator next(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    while (next != end) {
        std::smatch match = *next;
        std::string returnType = match[1];
        std::string functionName = match[2];
        std::string arguments = match[3];

        answ += QString::fromStdString(returnType + " " + functionName + "(" + arguments + ");\n");

        ++next;
    }
    if (answ.isEmpty()) {
        return "No function prototypes found.";
    }
    return answ;
}

QString MainWindow::Depth(QString line)
{
    QString answ;
    QStringList lineList = line.split("\n");
    int depth = 0;
    for (int i = 0; i < lineList.size(); ++i){
        std::regex pattern("\\b((if(\\([\\s\\S]+\\)){1}\\{)|(else\\s*\\{))");
        std::regex pattern2("((if\\([\\s\\S]+\\)\\{)|(else\\s*\\{))|(else\\s+if\\([\\s\\S]+\\)\\{)");
        std::smatch match;
        std::string str = lineList[i].toStdString();
        if (std::regex_search(str, match, pattern2)){
            depth++;
            answ += "Line " + QString::number(i + 1) + " depth is: " + QString::number(depth) + "\n";
        }
        pattern = ("\\}");
        if (std::regex_search(str, match, pattern)){
            depth--;
        }
    }
    if (answ.isEmpty()) {
        return "Nothing was found.";
    }
    return answ;
}


QString MainWindow::LocalVars(QString line)
{
    QString answ;
    QStringList lineList = line.split("\n");
    int bracket = 0;
    for (int i = 0; i < lineList.size(); ++i){
        if (bracket){
            std::regex pattern("\\b(?!(struct|class|void|namespace|return)\\s)(\\w+)((\\s+)|(\\s*(\\*)\\s*))(\\w+)\\s*(=\\s*(\\S+))?\\s*(,\\s*\\w+\\s*(=\\s*(\\S+))?)*\;");
            std::string str = lineList[i].toStdString();
            std::sregex_iterator next(str.begin(), str.end(), pattern);
            std::sregex_iterator end;
            while (next != end){
                std::smatch match = *next;
                answ += "line " + QString::number(i + 1) + ": " + QString::fromStdString(match[0].str()) + "\n";
                ++next;
            }
        }
        if (std::count(lineList[i].begin(), lineList[i].end(), '{')) bracket++;
        if (std::count(lineList[i].begin(), lineList[i].end(), '}')) bracket--;
    }
    if (answ.isEmpty()) {
        return "No local variables found.";
    }
    return answ;
}

QString MainWindow::Changes(QString line)
{
    std::string input = line.toStdString();
    QString answ;
    int line_num = 0;
    std::smatch match;
    int pos = 0;
    std::regex pattern("(\\b\\w+\\b)((\\[[^\\]]*\\])*)\\s*=\\s*(.*);");
    std::sregex_iterator next(input.begin(), input.end(), pattern);
    std::sregex_iterator end;
    while (next != end){
        std::smatch match = *next;
        pos = next->position();
        line_num = std::count(input.begin(), input.begin() + pos, '\n') + 1;
        answ += "line " + QString::number(line_num) + ": " + QString::fromStdString(match[0].str()) + "\n";
        ++next;
    }
    if (answ.isEmpty()) {
        return "No changes found.";
    }
    return answ;
}

QString MainWindow::Errors(QString s)
{
   std::string code = s.toStdString();
   QString result;
   std::regex pattern2("((const)\\s+(bool)\\s+([a-z]*)\\s*(=)\\s*(true|false)\\s*);");
   std::string buf;
   std::cmatch match2;
   while(std::regex_search(code.c_str(),match2,pattern2))
   {
       buf = "while(";
       buf += match2[4].str().c_str();
       buf.push_back(')');

       QStringList lineList = s.split('\n');
       for(int i=0;i<lineList.size(); ++i)
       {
           if(!strcmp(buf.c_str(),lineList[i].toStdString().c_str()))
           {
               result+=match2[1].str().c_str();
               result+='\n';
               result+=lineList[i];
               result+='\n';
           }
       }
       code = match2.suffix().first;
   }
   result+='\n';
   std::regex pattern("(while\\(true\\)|while\\(false\\))");
   std::cmatch match;
   while(std::regex_search(code.c_str(),match,pattern))
   {
       result+=match.str().c_str();
       result+='\n';
       code = match.suffix().first;
   }
   if (result=='\n') return "No errors were found";
   return result;
}

void MainWindow::on_actionOpen_File_triggered()
{
   QString filename = QFileDialog::getOpenFileName(this,"Bebra","/Users/anterg0/Desktop","Text files (*.txt);; All C++ files (*.cpp *.cc *.C *.cxx *.c++)");
   QString bebra;
   QFile file(filename);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       QMessageBox::critical(this,"Error","File couldn't be open.");
       return;
   }
   while (!file.atEnd()) {
       bebra += file.readLine();
   }
   ui->textBrowser->setText(bebra);
}


void MainWindow::on_pStructs_clicked()
{
   QMessageBox::information(this,"bebra",Struct(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pVar_clicked()
{
    QMessageBox::information(this,"bebra",Vars(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pLocVar_clicked()
{
    QMessageBox::information(this,"bebra",LocalVars(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pOver_clicked()
{
    QMessageBox::information(this,"bebra",Overrides(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pProt_clicked()
{
    QMessageBox::information(this,"bebra",Proto(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pDep_clicked()
{
    QMessageBox::information(this,"bebra",Depth(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pVarChan_clicked()
{
    QMessageBox::information(this,"bebra",Changes(ui->textBrowser->toPlainText()));
}


void MainWindow::on_pErr_clicked()
{
    QMessageBox::information(this,"bebra",Errors(ui->textBrowser->toPlainText()));
}

