#include "githubapi.h"
#include <QDebug>

GitHubApi::GitHubApi(QObject *parent) : QObject(parent)
{
    m_ghBase.setUrl("https://api.github.com");
    m_ghCat.clear();
    m_ghQuery.clear();
}

/*!
 * \brief GitHubApi::ghGetOrgsReposRul 获取组织的所有仓库
 * \return url 要查询的 url
 * \see https://developer.github.com/v3/repos/#list-public-repositories
 */
QUrl GitHubApi::ghGetOrgsReposRul()
{
    QString qstUrl = m_ghBase.toString();
    qstUrl += "/orgs/linuxdeepin/repos";
    QUrl url(qstUrl);

//    QUrlQuery query;
//    query.addQueryItem("rel", "next");
//    url.setQuery(query);

    return url;
}
