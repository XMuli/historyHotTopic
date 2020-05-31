#include "network.h"

NetWork::NetWork(QObject *parent) : QObject(parent)
{
    GitHubApi gh;
    m_manager = new QNetworkAccessManager(this);

    QUrl url;
    QUrlQuery query;
    for (int i = 1; i <= 8; i++) {
        query.clear();
        query.addQueryItem("page", QString::number(i, 10));
        url = gh.ghGetOrgsReposRul(query);
        m_request = new QNetworkRequest(url);

        qDebug()<<"@@@@@@@@"<<url;
        m_reply = m_manager->get(*m_request);
    }



//    m_reply = m_manager->get(*m_request);
    connect(m_manager, &QNetworkAccessManager::finished, this, &NetWork::onGhGetAllRepo);

//    QUrlQuery query2;
//    query2.addQueryItem("page", "2");
//    QNetworkRequest *reqyest2 = new QNetworkRequest(gh.ghGetOrgsReposRul(query2));
//    reply2 = m_manager->get(*reqyest2);

//    qDebug()<<"---01---"<<gh.ghGetOrgsReposRul(query);

//    std::string ss = "{ \"happy\": true, \"pi\": 3.141 }";
//    json j = json::parse(ss);

////    QString qstData = QString::fromStdString(strData);
//    std::cout<<"---01---"<<j[0];
}

/*!
 * \brief NetWork::onGhGetAllRepo 查询某组织下的所有仓库以及默认分支名称
 * \param reply
 */
void NetWork::onGhGetAllRepo(QNetworkReply *reply)
{
    qDebug()<<"---------02-------"<<&reply;

    QByteArray qbyData = reply->readAll();
    std::string strData = qbyData.toStdString();

    json js = json::parse(strData);

    static int i = 0;
    for (json::iterator it = js.begin(); it != js.end(); it++) {
        json jsTemp(*it);
        std::cout <<"i:"<<i++ <<"   "<<jsTemp["name"]<<"  default_branch:"<<jsTemp["default_branch"]<<"   Archived:"<<jsTemp["archived"]<<"  \n";
        std::cout.flush();
    }

    reply->deleteLater();

    //接续总的页数
//    QByteArray qbytArry;

//    if (m_reply->hasRawHeader("link")) {
//        qbytArry = m_reply->rawHeader("link");
//        bool ok1 = false;
//        bool ok2 = false;
//        QString qstrLink = QString::fromStdString(qbytArry.toStdString());
//        QString qstr1 = qstrLink.section('>', 0, 0);
//        QString qstr2 = qstrLink.section('>', 1, 1);
//        int nNextPage = qstr1.section('=', 1, 1).toUInt(&ok1, 10);  //下一页的页数
//        int nAllPage = qstr2.section('=', 2, 2).toUInt(&ok2, 10);  //总的页数
//        qDebug()<<"--01--"<<qstrLink<<qstr1<<qstr2<<"\n"<<"@"<<nNextPage<<"@"<<nAllPage;
//    } else {
//        qDebug()<<"hasRawHeader(\"link\") == false";
//    }

}
