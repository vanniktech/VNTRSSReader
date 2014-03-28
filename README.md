VNTRSSReader
============

This is a C++ library built on top of Qt, which allows you to consume RSS feeds, licensed under the GPL v2 terms. It is used in the [SpeedReader application](https://github.com/vanniktech/SpeedReader).
If you have any ideas on how to improve the library or its code, simply write an [email](mailto:niklas.baudy@vanniktech.de) to me or fork the library. If you have any problems or you have found any issues or bugs, feel free to report them.

## Features
- only RSS v2 is supported so far
- nearly every attribute of the channel and entry object's are available through the library

## Further plans
- support more protocols like ATOM or RSS v0.91/v1
- automatically download the images and provide them for the library user
- parse pubDate into QDateTime

## Sample Code
There is also an example project in this Git repository, where you can take a look at the library itself. Please read the INSTALL document if you want to execute / test the Example project.

**Class.h**
```
#include <QObject>

#include <vntrssreader.h>
#include <vntrsschannel.h>

class RSS : public QObject {
    Q_OBJECT
public slots:
    void loadedRSS(VNTRSSChannel* rssChannel, QString errorMessage);

public:
    explicit Class(QObject *parent = 0);
    ~Class();
    void loadRSS(QUrl url);

private:
    VNTRSSReader* mRSSReader;
};
```

**Class.cpp**
```
#include "class.h"

#include <QDebug>

Class::Class(QObject *parent) : QObject(parent) {
    mRSSReader = new VNTRSSReader();
	QObject::connect(mRSSReader, SIGNAL(loadedRSS(VNTRSSChannel*, QString)), this, SLOT(loadedRSS(VNTRSSChannel*, QString)));
    
    // Proxy configuration
    // Use this if you don't want to use a proxy
    QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);

    // Use this if you do want to use a specific proxy
    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setHostName("proxy.example.com");
    proxy.setPort(1080);
    proxy.setUser("username");
    proxy.setPassword("password");
    QNetworkProxy::setApplicationProxy(proxy);

    // Use this if you want Qt to do the work and figure the proxy out
    QNetworkProxyFactory::setUseSystemConfiguration(true);
}

Class::~Class() {
    delete mRSSReader;
}

void Class::loadRSS(QUrl url) {
	mRSSReader->load(url;)
}

void Class::loadedRSS(VNTRSSChannel* rssChannel, QString errorMessage) {
    if (!errorMessage.isEmpty()) {
        qDebug() << errorMessage;
        delete rssChannel;
        return;
    }

    QList<VNTRSSItem> items = rssChannel->getItems();

    foreach (VNTRSSItem item, items) {
        qDebug() << item.toString();
    }

    delete rssChannel;
}
```