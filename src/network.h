#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QMap>
#include <iostream>

#include "apigithub.h"
#include "winrepinfo.h"

#include "json.hpp"
using json = nlohmann::json;

class NetWork : public QObject
{
    Q_OBJECT
public:
    explicit NetWork(QObject *parent = nullptr);
    ~NetWork();


    void ghRepHasSpeBra();

public slots:
    void onGhGetAllRepo(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_manager;
    QNetworkRequest *m_request;
    QNetworkReply *m_reply;

    QMap<std::string, bool> m_map;

    WinRepInfo *m_winTabInfo;
    ApiGitHub *m_apiGh;
};

#endif // NETWORK_H
