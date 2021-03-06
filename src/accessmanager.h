#ifndef ACCESSMANAGER_H
#define ACCESSMANAGER_H

#include <QHash>
#include <QNetworkAccessManager>
#include <QUrl>

class NetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    NetworkAccessManager(QObject *parent = NULL);
    QNetworkReply *get(const QNetworkRequest &request);
    void setProxy(const QString &proxyType, const QString &proxy, int port);

private:
    QStringList header_urls;
    QStringList proxy_urls;
    QNetworkAccessManager *amForUnblock;
};

extern NetworkAccessManager *access_manager;
extern QStringList unseekable_hosts;
extern QHash<QString,QByteArray> referer_table;
extern QHash<QString,QByteArray> ua_table;
QByteArray generateUA(const QUrl &url);

#define DEFAULT_UA \
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_6) "\
    "AppleWebKit/605.1.15 (KHTML, like Gecko) "\
    "Version/12.0.1 Safari/605.1.15"

#endif // NETWORKMANAGER_H
