/********************************************************************************
** Form generated from reading UI file 'savesuccess.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVESUCCESS_H
#define UI_SAVESUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saveSuccess
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *saveSuccess)
    {
        if (saveSuccess->objectName().isEmpty())
            saveSuccess->setObjectName("saveSuccess");
        saveSuccess->resize(400, 200);
        saveSuccess->setMinimumSize(QSize(400, 200));
        saveSuccess->setMaximumSize(QSize(400, 200));
        verticalLayoutWidget = new QWidget(saveSuccess);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, -10, 130, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(saveSuccess);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, saveSuccess, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, saveSuccess, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(saveSuccess);
    } // setupUi

    void retranslateUi(QDialog *saveSuccess)
    {
        saveSuccess->setWindowTitle(QCoreApplication::translate("saveSuccess", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("saveSuccess", "\320\244\320\260\320\271\320\273 \320\261\321\213\320\273 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saveSuccess: public Ui_saveSuccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVESUCCESS_H
