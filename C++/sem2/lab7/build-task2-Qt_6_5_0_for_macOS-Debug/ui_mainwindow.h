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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *addSet;
    QLineEdit *addValSet;
    QPushButton *delSet;
    QLineEdit *delValSet;
    QPushButton *findSet;
    QLineEdit *findValSet;
    QPushButton *outputSet;
    QLabel *outputLabelSet;
    QLabel *label;
    QTableWidget *tableSet;
    QPushButton *clearSet;
    QLabel *label_2;
    QLineEdit *findKeyMap;
    QLineEdit *addValMap;
    QLabel *outputLabelMap;
    QPushButton *findMap;
    QTableWidget *tableMap;
    QPushButton *delMap;
    QPushButton *clearMap;
    QPushButton *addMap;
    QPushButton *outputMap;
    QLineEdit *delKeyMap;
    QLineEdit *addKeyMap;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        addSet = new QPushButton(centralwidget);
        addSet->setObjectName("addSet");
        addSet->setGeometry(QRect(10, 260, 100, 32));
        addValSet = new QLineEdit(centralwidget);
        addValSet->setObjectName("addValSet");
        addValSet->setGeometry(QRect(140, 270, 113, 21));
        delSet = new QPushButton(centralwidget);
        delSet->setObjectName("delSet");
        delSet->setGeometry(QRect(10, 310, 100, 32));
        delValSet = new QLineEdit(centralwidget);
        delValSet->setObjectName("delValSet");
        delValSet->setGeometry(QRect(130, 310, 113, 21));
        findSet = new QPushButton(centralwidget);
        findSet->setObjectName("findSet");
        findSet->setGeometry(QRect(10, 360, 100, 32));
        findValSet = new QLineEdit(centralwidget);
        findValSet->setObjectName("findValSet");
        findValSet->setGeometry(QRect(130, 370, 113, 21));
        outputSet = new QPushButton(centralwidget);
        outputSet->setObjectName("outputSet");
        outputSet->setGeometry(QRect(10, 410, 100, 32));
        outputLabelSet = new QLabel(centralwidget);
        outputLabelSet->setObjectName("outputLabelSet");
        outputLabelSet->setGeometry(QRect(150, 420, 58, 16));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 91, 16));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        tableSet = new QTableWidget(centralwidget);
        if (tableSet->columnCount() < 2)
            tableSet->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSet->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableSet->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableSet->setObjectName("tableSet");
        tableSet->setGeometry(QRect(10, 40, 256, 192));
        clearSet = new QPushButton(centralwidget);
        clearSet->setObjectName("clearSet");
        clearSet->setGeometry(QRect(60, 480, 100, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(600, 10, 91, 16));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        findKeyMap = new QLineEdit(centralwidget);
        findKeyMap->setObjectName("findKeyMap");
        findKeyMap->setGeometry(QRect(620, 370, 113, 21));
        addValMap = new QLineEdit(centralwidget);
        addValMap->setObjectName("addValMap");
        addValMap->setGeometry(QRect(690, 270, 113, 21));
        outputLabelMap = new QLabel(centralwidget);
        outputLabelMap->setObjectName("outputLabelMap");
        outputLabelMap->setGeometry(QRect(640, 420, 58, 16));
        findMap = new QPushButton(centralwidget);
        findMap->setObjectName("findMap");
        findMap->setGeometry(QRect(500, 360, 100, 32));
        tableMap = new QTableWidget(centralwidget);
        if (tableMap->columnCount() < 2)
            tableMap->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableMap->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableMap->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableMap->setObjectName("tableMap");
        tableMap->setGeometry(QRect(500, 40, 256, 192));
        delMap = new QPushButton(centralwidget);
        delMap->setObjectName("delMap");
        delMap->setGeometry(QRect(500, 310, 100, 32));
        clearMap = new QPushButton(centralwidget);
        clearMap->setObjectName("clearMap");
        clearMap->setGeometry(QRect(550, 480, 100, 32));
        addMap = new QPushButton(centralwidget);
        addMap->setObjectName("addMap");
        addMap->setGeometry(QRect(500, 260, 100, 32));
        outputMap = new QPushButton(centralwidget);
        outputMap->setObjectName("outputMap");
        outputMap->setGeometry(QRect(500, 410, 100, 32));
        delKeyMap = new QLineEdit(centralwidget);
        delKeyMap->setObjectName("delKeyMap");
        delKeyMap->setGeometry(QRect(620, 310, 113, 21));
        addKeyMap = new QLineEdit(centralwidget);
        addKeyMap->setObjectName("addKeyMap");
        addKeyMap->setGeometry(QRect(590, 250, 113, 21));
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
        addSet->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        delSet->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        findSet->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        outputSet->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
        outputLabelSet->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "My Set", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSet->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSet->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        clearSet->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "My Map", nullptr));
        outputLabelMap->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        findMap->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableMap->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableMap->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        delMap->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        clearMap->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        addMap->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        outputMap->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
