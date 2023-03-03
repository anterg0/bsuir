#include "findname.h"
#include "ui_findname.h"

findName::findName(MainWindow *mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findName),
    m_mainWindow(mainWindow)
{
    ui->setupUi(this);
}

findName::~findName()
{
    delete ui;
}

void findName::on_pushButton_clicked() {
    QString query = ui->lineEdit->text().toLower();
    QComboBox *comboBox = m_mainWindow->getComboBox();
    int count = comboBox->count();
    for (int i = 0; i < count;i++) {
        QString name = comboBox->itemText(i).toLower();
        if (name == query) {
            comboBox->setCurrentIndex(i);
            this->close();
        }
    }
}
