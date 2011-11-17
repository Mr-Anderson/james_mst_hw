#ifndef USERNAME_H
#define USERNAME_H

#include <QDialog>

namespace Ui {
    class Username;
}

class Username : public QDialog
{
    Q_OBJECT

public:
    explicit Username(QWidget *parent = 0);
    QString getName();

    ~Username();

private slots:
    void on_lineEdit_returnPressed();

    void on_buttonBox_accepted();

private:
    Ui::Username *ui;
};

#endif // USERNAME_H
