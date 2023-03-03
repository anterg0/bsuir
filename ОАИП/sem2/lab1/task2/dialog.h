#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    Ui::dialog *ui;
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

private:
};

#endif // DIALOG_H
