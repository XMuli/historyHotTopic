#include "apigithub.h"
#include <QDebug>

ApiGitHub::ApiGitHub(QObject *parent) : QObject(parent)
{
    m_ghBase.setUrl("https://api.github.com");
    m_ghCat.clear();
    m_ghQuery.clear();
}

/*!
 * \brief ApiGitHub::ghGetOrgsReposRul 获取组织的所有仓库
 * \param query 设置获取翻页结果
 * \return 总的查询链接
 * \see https://developer.github.com/v3/repos/#list-public-repositories
 */
QUrl ApiGitHub::ghGetOrgsReposRul(QUrlQuery query)
{
    QString qstUrl = m_ghBase.toString();
    qstUrl += "/orgs/linuxdeepin/repos";
    QUrl url(qstUrl);
    url.setQuery(query);

    return url;
}

/*!
 * \brief ApiGitHub::ghGetReposBranches 获取某仓库的所有分支
 * \param ower 仓库拥有者
 * \param repo 仓库名
 * \param query 查询的额外参数
 * \return 总的查询链接
 * \see https://developer.github.com/v3/repos/branches/#list-branches   repos/:owner/:repo/branches
 */
QUrl ApiGitHub::ghGetReposBranches(QString ower, QString repo, QUrlQuery query)
{
    QString qstUrl = m_ghBase.toString();
    qstUrl += "/orgs/linuxdeepin/repos";
    QUrl url(qstUrl);
    url.setQuery(query);

    return url;
}
