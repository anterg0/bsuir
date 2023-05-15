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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pStructs;
    QPushButton *pVar;
    QPushButton *pLocVar;
    QPushButton *pOver;
    QPushButton *pProt;
    QPushButton *pDep;
    QPushButton *pVarChan;
    QPushButton *pErr;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(13, 10, 551, 531));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(570, 10, 221, 531));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pStructs = new QPushButton(verticalLayoutWidget);
        pStructs->setObjectName("pStructs");

        verticalLayout->addWidget(pStructs);

        pVar = new QPushButton(verticalLayoutWidget);
        pVar->setObjectName("pVar");

        verticalLayout->addWidget(pVar);

        pLocVar = new QPushButton(verticalLayoutWidget);
        pLocVar->setObjectName("pLocVar");

        verticalLayout->addWidget(pLocVar);

        pOver = new QPushButton(verticalLayoutWidget);
        pOver->setObjectName("pOver");

        verticalLayout->addWidget(pOver);

        pProt = new QPushButton(verticalLayoutWidget);
        pProt->setObjectName("pProt");

        verticalLayout->addWidget(pProt);

        pDep = new QPushButton(verticalLayoutWidget);
        pDep->setObjectName("pDep");

        verticalLayout->addWidget(pDep);

        pVarChan = new QPushButton(verticalLayoutWidget);
        pVarChan->setObjectName("pVarChan");

        verticalLayout->addWidget(pVarChan);

        pErr = new QPushButton(verticalLayoutWidget);
        pErr->setObjectName("pErr");

        verticalLayout->addWidget(pErr);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\321\203\320\262\321\213, parser", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        pStructs->setText(QCoreApplication::translate("MainWindow", "Parse Structs", nullptr));
        pVar->setText(QCoreApplication::translate("MainWindow", "Parse Variables", nullptr));
        pLocVar->setText(QCoreApplication::translate("MainWindow", "Parse Local Variables", nullptr));
        pOver->setText(QCoreApplication::translate("MainWindow", "Parse Overrides", nullptr));
        pProt->setText(QCoreApplication::translate("MainWindow", "Parse Prototypes", nullptr));
        pDep->setText(QCoreApplication::translate("MainWindow", "Parse Depth", nullptr));
        pVarChan->setText(QCoreApplication::translate("MainWindow", "Parse Var Changes", nullptr));
        pErr->setText(QCoreApplication::translate("MainWindow", "Parse Errors", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
