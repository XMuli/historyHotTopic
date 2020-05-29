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
 * \return
 */
QUrl GitHubApi::ghGetOrgsReposRul()
{
    QString qstUrl = m_ghBase.toString();
    qstUrl += "/orgs/linuxdeepin/repos";
    QUrl url(qstUrl);
    return url;
}
