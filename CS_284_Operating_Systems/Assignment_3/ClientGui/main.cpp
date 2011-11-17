#include <QtGui/QApplication>
#include "clientgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientGui w;
    w.show();

    return a.exec();
}
