#include "network.h"

NetWork::NetWork(QObject *parent) : QObject(parent)
{
    GitHubApi gh;
    m_manager = new QNetworkAccessManager(this);
    m_request = new QNetworkRequest(gh.ghGetOrgsReposRul());
    m_replyGet = m_manager->get(*m_request);
    connect(m_manager, &QNetworkAccessManager::finished, this, &NetWork::onGhGetAllRepo);

    qDebug()<<"---01---"<<gh.ghGetOrgsReposRul();

//    std::string ss = "{ \"happy\": true, \"pi\": 3.141 }";
//    json j = json::parse(ss);

////    QString qstData = QString::fromStdString(strData);
//    std::cout<<"---01---"<<j[0];
}

void NetWork::onGhGetAllRepo(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    QByteArray qbyData = m_replyGet->readAll();
    std::string strData = qbyData.toStdString();

    json js = json::parse(strData);

//    std::cout<<js.dump(4)<<js;
//    std::cout.flush();

    int i = 0;
    for (json::iterator it = js.begin(); it != js.end(); it++) {
        json jsTemp(*it);
        std::cout << jsTemp["name"]<<"  default_branch:"<<jsTemp["default_branch"]<<"   i:"<<i++<<"  \n";
        std::cout.flush();
//        std::cout << *it<<"\n\n";
//      std::cout << *it << "   #########  i: "<< i++<<"    "<<"\n\n";
    }


//    QVariant qvar =  m_replyGet->header(QNetworkRequest::ETagHeader);  //ETagHeader  LastModifiedHeader
//    qDebug() << qvar.toString();

    QByteArray qbytArry;

    if (m_replyGet->hasRawHeader("link")) {
        qbytArry = m_replyGet->rawHeader("link");
    }

    qDebug() << QString::fromStdString(qbytArry.toStdString());


//    json js = json::array(strData);
//    std::count<<js[0];

//    std::string ss = "[{ \"happy\": true, \"pi\": 3.141 }]";
//    json j = json::parse(ss);

//    QString qstData = QString::fromStdString(strData);
//    qDebug()<<qstData;
}
