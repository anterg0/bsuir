/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot;
    QLineEdit *AddLine;
    QPushButton *AddButton;
    QPushButton *SearchButton;
    QLineEdit *SearchLine;
    QPushButton *pushButton;
    QLineEdit *ModuloLine;
    QPushButton *ModuloButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName("plot");
        plot->setGeometry(QRect(79, 39, 591, 301));
        AddLine = new QLineEdit(centralwidget);
        AddLine->setObjectName("AddLine");
        AddLine->setGeometry(QRect(50, 390, 113, 21));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(60, 420, 100, 32));
        SearchButton = new QPushButton(centralwidget);
        SearchButton->setObjectName("SearchButton");
        SearchButton->setGeometry(QRect(260, 420, 100, 32));
        SearchLine = new QLineEdit(centralwidget);
        SearchLine->setObjectName("SearchLine");
        SearchLine->setGeometry(QRect(250, 390, 113, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(700, 510, 100, 32));
        ModuloLine = new QLineEdit(centralwidget);
        ModuloLine->setObjectName("ModuloLine");
        ModuloLine->setGeometry(QRect(460, 390, 121, 21));
        ModuloButton = new QPushButton(centralwidget);
        ModuloButton->setObjectName("ModuloButton");
        ModuloButton->setGeometry(QRect(470, 420, 111, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "add element", nullptr));
        SearchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "debug", nullptr));
        ModuloButton->setText(QCoreApplication::translate("MainWindow", "change modulo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
