#ifndef APIGITHUB_H
#define APIGITHUB_H

#include <QObject>
#include <QUrl>
#include <QUrlQuery>

/*!
 * \brief The ApiGitHub class github 上使用的 api 接口类调用；函数名称默认为 gh 开头
 */
class ApiGitHub : public QObject
{
    Q_OBJECT
public:
    explicit ApiGitHub(QObject *parent = nullptr);

    QUrl ghGetOrgsReposRul(QUrlQuery query);
    QUrl ghGetReposBranches(QString ower, QString repo, QUrlQuery query);

private:
    QUrl m_ghBase;
    QUrl m_ghCat;
    QUrlQuery m_ghQuery;
};

#endif // APIGITHUB_H
