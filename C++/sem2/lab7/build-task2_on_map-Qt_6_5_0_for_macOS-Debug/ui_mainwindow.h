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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QLineEdit *insKey;
    QLineEdit *insValue;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *containsButton;
    QLineEdit *containsKey;
    QPushButton *clearButtton;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *outputText;
    QPushButton *outputButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 376);
        MainWindow->setMinimumSize(QSize(800, 376));
        MainWindow->setMaximumSize(QSize(800, 376));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(9, 19, 781, 301));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        insertButton = new QPushButton(horizontalLayoutWidget_3);
        insertButton->setObjectName("insertButton");

        horizontalLayout->addWidget(insertButton);

        insKey = new QLineEdit(horizontalLayoutWidget_3);
        insKey->setObjectName("insKey");

        horizontalLayout->addWidget(insKey);

        insValue = new QLineEdit(horizontalLayoutWidget_3);
        insValue->setObjectName("insValue");

        horizontalLayout->addWidget(insValue);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        containsButton = new QPushButton(horizontalLayoutWidget_3);
        containsButton->setObjectName("containsButton");

        horizontalLayout_2->addWidget(containsButton);

        containsKey = new QLineEdit(horizontalLayoutWidget_3);
        containsKey->setObjectName("containsKey");

        horizontalLayout_2->addWidget(containsKey);


        verticalLayout_2->addLayout(horizontalLayout_2);

        clearButtton = new QPushButton(horizontalLayoutWidget_3);
        clearButtton->setObjectName("clearButtton");

        verticalLayout_2->addWidget(clearButtton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        outputText = new QPlainTextEdit(horizontalLayoutWidget_3);
        outputText->setObjectName("outputText");

        verticalLayout->addWidget(outputText);

        outputButton = new QPushButton(horizontalLayoutWidget_3);
        outputButton->setObjectName("outputButton");

        verticalLayout->addWidget(outputButton);


        horizontalLayout_3->addLayout(verticalLayout);

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
        insertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        insKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "key(int)", nullptr));
        insValue->setPlaceholderText(QCoreApplication::translate("MainWindow", "value(string)", nullptr));
        containsButton->setText(QCoreApplication::translate("MainWindow", "contains", nullptr));
        containsKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "key(int)", nullptr));
        clearButtton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        outputButton->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
