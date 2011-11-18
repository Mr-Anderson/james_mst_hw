#ifndef HOSTNAME_H
#define HOSTNAME_H

#include <QWidget>
#include "../shared.h"

namespace Ui {
    class Hostname;
}

class Hostname : public QWidget
{
    Q_OBJECT

public:
    explicit Hostname(QWidget *parent = 0);
    ~Hostname();

    struct hostent *host;
    int soc;
    sockaddr_in server_addr = { AF_INET, htons( SERVER_PORT ) };
    char buf[MAX_BUFFER_SIZE];
    struct hostent *host;


private slots:
    void on_lineEdit_returnPressed();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Hostname *ui;
    void setHostname();
};

#endif // HOSTNAME_H
