#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetWork *network = new NetWork();

    return a.exec();
}
