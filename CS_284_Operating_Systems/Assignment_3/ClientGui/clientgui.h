#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include <QMainWindow>

namespace Ui {
    class ClientGui;
}

class ClientGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientGui(QWidget *parent = 0);
    ~ClientGui();

private slots:
    void on_actionCange_User_activated();

    void on_sendButton_clicked();

private:
    Ui::ClientGui *ui;

    void sendMsg();

};

#endif // CLIENTGUI_H
