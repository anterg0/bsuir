#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QDialog>

namespace Ui {
class bookInfo;
}

class bookInfo : public QDialog
{
    Q_OBJECT

public:
    Ui::bookInfo *ui;
    explicit bookInfo(QWidget *parent = nullptr);
    ~bookInfo();

private:
};

#endif // BOOKINFO_H
