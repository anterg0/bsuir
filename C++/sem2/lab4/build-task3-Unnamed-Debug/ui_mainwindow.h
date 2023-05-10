/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QPlainTextEdit *code;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QTextBrowser *result;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *locvarB;
    QPushButton *variablesB;
    QVBoxLayout *verticalLayout_2;
    QPushButton *classB;
    QPushButton *changesB;
    QVBoxLayout *verticalLayout;
    QPushButton *functionsB;
    QPushButton *overloadB;
    QVBoxLayout *verticalLayout_3;
    QPushButton *depthB;
    QPushButton *logicB;
    QVBoxLayout *verticalLayout_4;
    QPushButton *readB;
    QPushButton *clearB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_6->addWidget(label);

        code = new QPlainTextEdit(centralwidget);
        code->setObjectName(QString::fromUtf8("code"));

        verticalLayout_6->addWidget(code);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_7->addWidget(label_2);

        result = new QTextBrowser(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));

        verticalLayout_7->addWidget(result);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        locvarB = new QPushButton(centralwidget);
        locvarB->setObjectName(QString::fromUtf8("locvarB"));

        verticalLayout_5->addWidget(locvarB);

        variablesB = new QPushButton(centralwidget);
        variablesB->setObjectName(QString::fromUtf8("variablesB"));

        verticalLayout_5->addWidget(variablesB);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        classB = new QPushButton(centralwidget);
        classB->setObjectName(QString::fromUtf8("classB"));

        verticalLayout_2->addWidget(classB);

        changesB = new QPushButton(centralwidget);
        changesB->setObjectName(QString::fromUtf8("changesB"));

        verticalLayout_2->addWidget(changesB);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        functionsB = new QPushButton(centralwidget);
        functionsB->setObjectName(QString::fromUtf8("functionsB"));

        verticalLayout->addWidget(functionsB);

        overloadB = new QPushButton(centralwidget);
        overloadB->setObjectName(QString::fromUtf8("overloadB"));

        verticalLayout->addWidget(overloadB);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        depthB = new QPushButton(centralwidget);
        depthB->setObjectName(QString::fromUtf8("depthB"));

        verticalLayout_3->addWidget(depthB);

        logicB = new QPushButton(centralwidget);
        logicB->setObjectName(QString::fromUtf8("logicB"));

        verticalLayout_3->addWidget(logicB);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        readB = new QPushButton(centralwidget);
        readB->setObjectName(QString::fromUtf8("readB"));

        verticalLayout_4->addWidget(readB);

        clearB = new QPushButton(centralwidget);
        clearB->setObjectName(QString::fromUtf8("clearB"));

        verticalLayout_4->addWidget(clearB);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_8);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        locvarB->setText(QCoreApplication::translate("MainWindow", "local variables", nullptr));
        variablesB->setText(QCoreApplication::translate("MainWindow", "variables", nullptr));
        classB->setText(QCoreApplication::translate("MainWindow", "classes structs arrays", nullptr));
        changesB->setText(QCoreApplication::translate("MainWindow", "var/array changes", nullptr));
        functionsB->setText(QCoreApplication::translate("MainWindow", "functions", nullptr));
        overloadB->setText(QCoreApplication::translate("MainWindow", "overload functions", nullptr));
        depthB->setText(QCoreApplication::translate("MainWindow", "depth", nullptr));
        logicB->setText(QCoreApplication::translate("MainWindow", "logic errors", nullptr));
        readB->setText(QCoreApplication::translate("MainWindow", "read file", nullptr));
        clearB->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
