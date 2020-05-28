#ifndef ZHIHUAPI_H
#define ZHIHUAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


class ZhiHuApi
{
    Q_OBJECT
public:
    ZhiHuApi();
    ~ZhiHuApi();

     void zhGetPopuTopic();  //获取知乎每日热榜


private:
    QNetworkAccessManager *m_manager;
    QNetworkRequest *m_request;
    QNetworkReply *m_replyGet;
};

#endif // ZHIHUAPI_H
