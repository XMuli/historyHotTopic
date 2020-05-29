#include "network.h"

NetWork::NetWork(QObject *parent) : QObject(parent)
{
    GitHubApi gh;
    m_manager = new QNetworkAccessManager(this);
    m_request = new QNetworkRequest(gh.ghGetOrgsReposRul());
    m_replyGet = m_manager->get(*m_request);
    connect(m_manager, &QNetworkAccessManager::finished, this, &NetWork::onGhGetAllRepo);

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

    std::cout<<js.dump(4)<<js;
    std::cout.flush();

//    json js = json::array(strData);
//    std::count<<js[0];

//    std::string ss = "[{ \"happy\": true, \"pi\": 3.141 }]";
//    json j = json::parse(ss);

//    QString qstData = QString::fromStdString(strData);
//    qDebug()<<qstData;
}
