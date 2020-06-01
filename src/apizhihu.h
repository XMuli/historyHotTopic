#ifndef APIZHIHU_H
#define APIZHIHU_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

/*!
 * \brief The ApiZhiHu class 知乎感兴趣的 api 接口类调用；函数名称默认为 zh 开头
 */
class ApiZhiHu
{
public:
    ApiZhiHu();
    ~ApiZhiHu();

    void zhGetPopuTopic();  //获取知乎每日热榜


private:
   QNetworkAccessManager *m_manager;
   QNetworkRequest *m_request;
   QNetworkReply *m_replyGet;
};

#endif // APIZHIHU_H
