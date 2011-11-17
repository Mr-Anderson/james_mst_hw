#include "clientgui.h"
#include "ui_clientgui.h"

ClientGui::ClientGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientGui)
{
    ui->setupUi(this);
}

ClientGui::~ClientGui()
{
    delete ui;
}

void ClientGui::on_actionCange_User_activated()
{

}
