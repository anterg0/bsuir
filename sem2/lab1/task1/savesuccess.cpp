#include "savesuccess.h"
#include "ui_savesuccess.h"

saveSuccess::saveSuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveSuccess)
{
    ui->setupUi(this);
}

saveSuccess::~saveSuccess()
{
    delete ui;
}
