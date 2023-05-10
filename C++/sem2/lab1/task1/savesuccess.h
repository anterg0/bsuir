#ifndef SAVESUCCESS_H
#define SAVESUCCESS_H

#include <QDialog>

namespace Ui {
class saveSuccess;
}

class saveSuccess : public QDialog
{
    Q_OBJECT

public:
    explicit saveSuccess(QWidget *parent = nullptr);
    ~saveSuccess();
    Ui::saveSuccess *ui;
private:
};

#endif // SAVESUCCESS_H
