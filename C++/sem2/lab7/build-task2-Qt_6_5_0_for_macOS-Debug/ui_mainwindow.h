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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableSet;
    QHBoxLayout *horizontalLayout;
    QPushButton *addSet;
    QLineEdit *addValSet;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *delSet;
    QLineEdit *delValSet;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *findSet;
    QLineEdit *findValSet;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *outputSet;
    QLabel *outputLabelSet;
    QPushButton *clearSet;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tableMap;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addMap;
    QLineEdit *addKeyMap;
    QLineEdit *addValMap;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *delMap;
    QLineEdit *delKeyMap;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *findMap;
    QLineEdit *findKeyMap;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *outputMap;
    QLabel *outputLabelMap;
    QPushButton *clearMap;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1009, 596);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 501, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableSet = new QTableWidget(verticalLayoutWidget);
        if (tableSet->columnCount() < 2)
            tableSet->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSet->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableSet->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableSet->setObjectName("tableSet");

        verticalLayout->addWidget(tableSet);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addSet = new QPushButton(verticalLayoutWidget);
        addSet->setObjectName("addSet");

        horizontalLayout->addWidget(addSet);

        addValSet = new QLineEdit(verticalLayoutWidget);
        addValSet->setObjectName("addValSet");

        horizontalLayout->addWidget(addValSet);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        delSet = new QPushButton(verticalLayoutWidget);
        delSet->setObjectName("delSet");

        horizontalLayout_2->addWidget(delSet);

        delValSet = new QLineEdit(verticalLayoutWidget);
        delValSet->setObjectName("delValSet");

        horizontalLayout_2->addWidget(delValSet);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        findSet = new QPushButton(verticalLayoutWidget);
        findSet->setObjectName("findSet");

        horizontalLayout_3->addWidget(findSet);

        findValSet = new QLineEdit(verticalLayoutWidget);
        findValSet->setObjectName("findValSet");

        horizontalLayout_3->addWidget(findValSet);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        outputSet = new QPushButton(verticalLayoutWidget);
        outputSet->setObjectName("outputSet");

        horizontalLayout_4->addWidget(outputSet);

        outputLabelSet = new QLabel(verticalLayoutWidget);
        outputLabelSet->setObjectName("outputLabelSet");

        horizontalLayout_4->addWidget(outputLabelSet);


        verticalLayout->addLayout(horizontalLayout_4);

        clearSet = new QPushButton(verticalLayoutWidget);
        clearSet->setObjectName("clearSet");

        verticalLayout->addWidget(clearSet);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(510, 0, 491, 541));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tableMap = new QTableWidget(verticalLayoutWidget_2);
        if (tableMap->columnCount() < 2)
            tableMap->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableMap->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableMap->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableMap->setObjectName("tableMap");

        verticalLayout_2->addWidget(tableMap);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addMap = new QPushButton(verticalLayoutWidget_2);
        addMap->setObjectName("addMap");

        horizontalLayout_5->addWidget(addMap);

        addKeyMap = new QLineEdit(verticalLayoutWidget_2);
        addKeyMap->setObjectName("addKeyMap");

        horizontalLayout_5->addWidget(addKeyMap);

        addValMap = new QLineEdit(verticalLayoutWidget_2);
        addValMap->setObjectName("addValMap");

        horizontalLayout_5->addWidget(addValMap);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        delMap = new QPushButton(verticalLayoutWidget_2);
        delMap->setObjectName("delMap");

        horizontalLayout_7->addWidget(delMap);

        delKeyMap = new QLineEdit(verticalLayoutWidget_2);
        delKeyMap->setObjectName("delKeyMap");

        horizontalLayout_7->addWidget(delKeyMap);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        findMap = new QPushButton(verticalLayoutWidget_2);
        findMap->setObjectName("findMap");

        horizontalLayout_6->addWidget(findMap);

        findKeyMap = new QLineEdit(verticalLayoutWidget_2);
        findKeyMap->setObjectName("findKeyMap");

        horizontalLayout_6->addWidget(findKeyMap);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        outputMap = new QPushButton(verticalLayoutWidget_2);
        outputMap->setObjectName("outputMap");

        horizontalLayout_8->addWidget(outputMap);

        outputLabelMap = new QLabel(verticalLayoutWidget_2);
        outputLabelMap->setObjectName("outputLabelMap");

        horizontalLayout_8->addWidget(outputLabelMap);


        verticalLayout_2->addLayout(horizontalLayout_8);

        clearMap = new QPushButton(verticalLayoutWidget_2);
        clearMap->setObjectName("clearMap");

        verticalLayout_2->addWidget(clearMap);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1009, 24));
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
        label->setText(QCoreApplication::translate("MainWindow", "My Set", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSet->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSet->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        addSet->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        addValSet->setPlaceholderText(QCoreApplication::translate("MainWindow", "int", nullptr));
        delSet->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        delValSet->setPlaceholderText(QCoreApplication::translate("MainWindow", "int", nullptr));
        findSet->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        findValSet->setPlaceholderText(QCoreApplication::translate("MainWindow", "int", nullptr));
        outputSet->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
        outputLabelSet->setText(QString());
        clearSet->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "My Map", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableMap->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableMap->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        addMap->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        addKeyMap->setPlaceholderText(QCoreApplication::translate("MainWindow", "key(int)", nullptr));
        addValMap->setPlaceholderText(QCoreApplication::translate("MainWindow", "value(int)", nullptr));
        delMap->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        delKeyMap->setPlaceholderText(QCoreApplication::translate("MainWindow", "key(int)", nullptr));
        findMap->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        findKeyMap->setPlaceholderText(QCoreApplication::translate("MainWindow", "key(int)", nullptr));
        outputMap->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
        outputLabelMap->setText(QString());
        clearMap->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
