#ifndef ZHIHUAPI_H
#define ZHIHUAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

/*!
 * \brief The ZhiHuApi class 知乎感兴趣的 api 接口类调用；函数名称默认为 zh 开头
 */

class ZhiHuApi
{
//    Q_OBJECT
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
