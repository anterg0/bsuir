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
#include <QtWidgets/QSpinBox>
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
    QPushButton *strncpyString1;
    QPushButton *strncpyString2;
    QLineEdit *strncpyLine;
    QSpinBox *strncpyNum;
    QPushButton *strcatString1;
    QPushButton *strcatString2;
    QLineEdit *strcatLine;
    QPushButton *pushButton;
    QPushButton *strncatString2;
    QLineEdit *strncatLine;
    QPushButton *strncatString1;
    QSpinBox *strncatNum;
    QPushButton *memsetString2;
    QLineEdit *memsetLine;
    QPushButton *memsetString1;
    QSpinBox *memsetNum;
    QPushButton *strcmpString1;
    QLineEdit *strcmpLine;
    QPushButton *strcmpString2;
    QLineEdit *strncmpLine;
    QPushButton *strncmpString1;
    QPushButton *strncmpString2;
    QSpinBox *strncmpNum;
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
        strncpyString1 = new QPushButton(centralwidget);
        strncpyString1->setObjectName("strncpyString1");
        strncpyString1->setGeometry(QRect(200, 160, 100, 32));
        strncpyString2 = new QPushButton(centralwidget);
        strncpyString2->setObjectName("strncpyString2");
        strncpyString2->setGeometry(QRect(200, 200, 100, 32));
        strncpyLine = new QLineEdit(centralwidget);
        strncpyLine->setObjectName("strncpyLine");
        strncpyLine->setGeometry(QRect(190, 130, 121, 21));
        strncpyNum = new QSpinBox(centralwidget);
        strncpyNum->setObjectName("strncpyNum");
        strncpyNum->setGeometry(QRect(310, 180, 42, 22));
        strcatString1 = new QPushButton(centralwidget);
        strcatString1->setObjectName("strcatString1");
        strcatString1->setGeometry(QRect(420, 160, 100, 32));
        strcatString2 = new QPushButton(centralwidget);
        strcatString2->setObjectName("strcatString2");
        strcatString2->setGeometry(QRect(420, 200, 100, 32));
        strcatLine = new QLineEdit(centralwidget);
        strcatLine->setObjectName("strcatLine");
        strcatLine->setGeometry(QRect(410, 130, 121, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(660, 500, 100, 32));
        strncatString2 = new QPushButton(centralwidget);
        strncatString2->setObjectName("strncatString2");
        strncatString2->setGeometry(QRect(600, 200, 100, 32));
        strncatLine = new QLineEdit(centralwidget);
        strncatLine->setObjectName("strncatLine");
        strncatLine->setGeometry(QRect(590, 130, 121, 21));
        strncatString1 = new QPushButton(centralwidget);
        strncatString1->setObjectName("strncatString1");
        strncatString1->setGeometry(QRect(600, 160, 100, 32));
        strncatNum = new QSpinBox(centralwidget);
        strncatNum->setObjectName("strncatNum");
        strncatNum->setGeometry(QRect(720, 180, 42, 22));
        memsetString2 = new QPushButton(centralwidget);
        memsetString2->setObjectName("memsetString2");
        memsetString2->setGeometry(QRect(50, 360, 100, 32));
        memsetLine = new QLineEdit(centralwidget);
        memsetLine->setObjectName("memsetLine");
        memsetLine->setGeometry(QRect(40, 290, 121, 21));
        memsetLine->setMaxLength(1);
        memsetString1 = new QPushButton(centralwidget);
        memsetString1->setObjectName("memsetString1");
        memsetString1->setGeometry(QRect(50, 320, 100, 32));
        memsetNum = new QSpinBox(centralwidget);
        memsetNum->setObjectName("memsetNum");
        memsetNum->setGeometry(QRect(170, 340, 42, 22));
        strcmpString1 = new QPushButton(centralwidget);
        strcmpString1->setObjectName("strcmpString1");
        strcmpString1->setGeometry(QRect(270, 320, 100, 32));
        strcmpLine = new QLineEdit(centralwidget);
        strcmpLine->setObjectName("strcmpLine");
        strcmpLine->setGeometry(QRect(260, 290, 121, 21));
        strcmpLine->setMaxLength(32767);
        strcmpString2 = new QPushButton(centralwidget);
        strcmpString2->setObjectName("strcmpString2");
        strcmpString2->setGeometry(QRect(270, 360, 100, 32));
        strncmpLine = new QLineEdit(centralwidget);
        strncmpLine->setObjectName("strncmpLine");
        strncmpLine->setGeometry(QRect(470, 290, 121, 21));
        strncmpLine->setMaxLength(32767);
        strncmpString1 = new QPushButton(centralwidget);
        strncmpString1->setObjectName("strncmpString1");
        strncmpString1->setGeometry(QRect(480, 320, 100, 32));
        strncmpString2 = new QPushButton(centralwidget);
        strncmpString2->setObjectName("strncmpString2");
        strncmpString2->setGeometry(QRect(480, 360, 100, 32));
        strncmpNum = new QSpinBox(centralwidget);
        strncmpNum->setObjectName("strncmpNum");
        strncmpNum->setGeometry(QRect(590, 340, 42, 22));
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
        changeStringLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "strcpy", nullptr));
        changeString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        changeString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
        strncpyString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        strncpyString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
        strncpyLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "strncpy", nullptr));
        strcatString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        strcatString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
        strcatLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "strcat", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "debug", nullptr));
        strncatString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
        strncatLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "strncat", nullptr));
        strncatString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        memsetString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
        memsetLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "memset", nullptr));
        memsetString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        strcmpString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        strcmpLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "strcmp", nullptr));
        strcmpString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
        strncmpLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "strncmp", nullptr));
        strncmpString1->setText(QCoreApplication::translate("MainWindow", "string1", nullptr));
        strncmpString2->setText(QCoreApplication::translate("MainWindow", "string2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
