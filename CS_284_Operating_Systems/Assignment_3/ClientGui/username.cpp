#include "username.h"
#include "ui_username.h"

Username::Username(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Username)
{
    ui->setupUi(this);
}

Username::~Username()
{
    delete ui;
}

void Username::on_lineEdit_returnPressed()
{

}

void Username::on_buttonBox_accepted()
{

}
