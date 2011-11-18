#include "hostname.h"
#include "ui_hostname.h"

Hostname::Hostname(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hostname)
{
    ui->setupUi(this);
}

Hostname::~Hostname()
{
    delete ui;
}

void Hostname::on_lineEdit_returnPressed()
{
    setHostname(ui->hostname->value());
}

void Hostname::on_buttonBox_accepted()
{
    setHostname(ui->hostname->value());
}

void Hostname::on_buttonBox_rejected()
{

}

void Hostname::setHostname(char *)
{
    //translate the host name to hostent then place in server address
    if( ( host = gethostbyname( argv[1] ) ) == NULL )
    {
        printf( "%s: %s unknown host\n", argv[0], argv[1] );
        exit( 1 );
    }
    bcopy( host->h_addr_list[0], (char*)&server_addr.sin_addr, host->h_length );

    //open a new socket
    if( ( soc = socket( AF_INET, SOCK_STREAM, 0 ) ) == -1 )
    {
        perror( "client: socket failed" );
        exit( 1 );
    }

    //connect to the socket
    if( connect( soc, (struct sockaddr*)&server_addr,
         sizeof(server_addr) ) == -1 )
    {
        perror( "client: connect FAILED:" );
        exit( 1 );
    }
}



