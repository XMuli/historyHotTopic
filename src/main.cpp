#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "network.h"

//#include <iostream>
//#include "json.hpp"
//using json = nlohmann::json;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    NetWork *network = new NetWork();



//    std::string ss = "[{ \"happy\": true, \"pi\": 3.141 }]";
//    json js = json::parse(ss);

////    QString qstData = QString::fromStdString(strData);
//    std::cout<<"#######"<<js;
//    std::cout.flush();


    return a.exec();
}
