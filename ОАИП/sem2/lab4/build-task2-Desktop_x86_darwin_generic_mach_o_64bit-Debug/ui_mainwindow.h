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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *string1Label;
    QLineEdit *string1Edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *strlen1label;
    QLabel *strlen1;
    QVBoxLayout *verticalLayout_2;
    QLabel *string2Label;
    QLineEdit *string2Edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *strlen2label;
    QLabel *strlen2;
    QLineEdit *changeStringLine;
    QPushButton *changeString1;
    QPushButton *changeString2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 761, 77));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        string1Label = new QLabel(horizontalLayoutWidget);
        string1Label->setObjectName("string1Label");
        string1Label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(string1Label);

        string1Edit = new QLineEdit(horizontalLayoutWidget);
        string1Edit->setObjectName("string1Edit");
        string1Edit->setReadOnly(true);

        verticalLayout->addWidget(string1Edit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        strlen1label = new QLabel(horizontalLayoutWidget);
        strlen1label->setObjectName("strlen1label");
        strlen1label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(strlen1label);

        strlen1 = new QLabel(horizontalLayoutWidget);
        strlen1->setObjectName("strlen1");

        horizontalLayout_3->addWidget(strlen1);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        string2Label = new QLabel(horizontalLayoutWidget);
        string2Label->setObjectName("string2Label");
        string2Label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(string2Label);

        string2Edit = new QLineEdit(horizontalLayoutWidget);
        string2Edit->setObjectName("string2Edit");
        string2Edit->setReadOnly(true);

        verticalLayout_2->addWidget(string2Edit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        strlen2label = new QLabel(horizontalLayoutWidget);
        strlen2label->setObjectName("strlen2label");
        strlen2label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(strlen2label);

        strlen2 = new QLabel(horizontalLayoutWidget);
        strlen2->setObjectName("strlen2");

        horizontalLayout_4->addWidget(strlen2);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);

        changeStringLine = new QLineEdit(centralwidget);
        changeStringLine->setObjectName("changeStringLine");
        changeStringLine->setGeometry(QRect(40, 130, 121, 21));
        changeString1 = new QPushButton(centralwidget);
        changeString1->setObjectName("changeString1");
        changeString1->setGeometry(QRect(50, 160, 100, 32));
        changeString2 = new QPushButton(centralwidget);
        changeString2->setObjectName("changeString2");
        changeString2->setGeometry(QRect(50, 200, 100, 32));
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
        string1Label->setText(QCoreApplication::translate("MainWindow", "String1", nullptr));
        string1Edit->setText(QString());
        strlen1label->setText(QCoreApplication::translate("MainWindow", "mystrlen:", nullptr));
        strlen1->setText(QString());
        string2Label->setText(QCoreApplication::translate("MainWindow", "String2", nullptr));
        strlen2label->setText(QCoreApplication::translate("MainWindow", "mystrlen2:", nullptr));
        strlen2->setText(QString());
        changeStringLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "CHANGE STRING", nullptr));
        changeString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        changeString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
