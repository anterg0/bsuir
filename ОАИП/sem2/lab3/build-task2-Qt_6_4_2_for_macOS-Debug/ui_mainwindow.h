/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *firstMat;
    QLabel *secondMat;
    QPushButton *bruhButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(615, 390);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 221, 41));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(330, 20, 261, 41));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        firstMat = new QLabel(centralwidget);
        firstMat->setObjectName("firstMat");
        firstMat->setGeometry(QRect(40, 80, 241, 231));
        firstMat->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        secondMat = new QLabel(centralwidget);
        secondMat->setObjectName("secondMat");
        secondMat->setGeometry(QRect(340, 80, 241, 231));
        secondMat->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        bruhButton = new QPushButton(centralwidget);
        bruhButton->setObjectName("bruhButton");
        bruhButton->setGeometry(QRect(240, 0, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 615, 24));
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
        label->setText(QCoreApplication::translate("MainWindow", "FIRST MATRIX", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "SECOND MATRIX", nullptr));
        firstMat->setText(QString());
        secondMat->setText(QString());
        bruhButton->setText(QCoreApplication::translate("MainWindow", "bruh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
