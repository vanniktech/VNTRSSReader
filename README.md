VNTRSSReader
============

[![License](http://img.shields.io/:license-gpl2-blue.svg)](http://www.gnu.org/licenses/gpl-2.0.html)

This is a C++ library built on top of Qt, which allows you to consume RSS feeds, licensed under the GPL v2 terms. It is used in the [SpeedReader application](https://github.com/vanniktech/SpeedReader).
If you have any ideas on how to improve the library or its code, simply write an [email](mailto:niklas.baudy@vanniktech.de) to me or fork the library. If you have any problems or you have found any issues or bugs, feel free to report them.

## Features
- RSS v0.91, v1.0 and v2.0 are supported
- ATOM v1.0 is supported
- supports redirect urls
- nearly every attribute of the channel and entry / item object's are available through the library
- pubDate will be parsed conveniently into QDateTime
- option to automatically download the images and provide them for the library user
- variety of unit tests

## Further plans
- let me know if you have any

## Sample Code
If the things below are not enough information, you can have a look at the Unit Tests to get a deeper understanding.

**Class.h**
```c++
#include <QObject>

#include "vntrssreader.h"
#include "vntrsschannel.h"

class RSS : public QObject {
    Q_OBJECT

public slots:
    void loadedRSS(QList<VNTRSSChannel*> rssChannels);

public:
    explicit Class(QObject *parent = 0);
    ~Class();

    void loadRSS(const QUrl &url);
    void loadRSS(const QList<QUrl> &urls);

private:
    VNTRSSReader* mRSSReader;
};
```

**Class.cpp**
```c++
#include "class.h"

#include <QDebug>

Class::Class(QObject *parent) : QObject(parent) {
    mRSSReader = new VNTRSSReader();
    QObject::connect(mRSSReader, SIGNAL(loadedRSS(QList<VNTRSSChannel*>)), this, SLOT(loadedRSS(QList<VNTRSSChannel*>)));

    // Use this if you don't want to use a proxy
    QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);

    // Use this if you do want to use a specific proxy
    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::HttpProxy);
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

void Class::loadRSS(const QUrl &url) {
    mRSSReader->load(url);  // will automatically download the images. pass false as a second argument if you don't want that
}

void Class::loadRSS(const QList<QUrl> &urls) {
    mRSSReader->load(urls); // will automatically download the images. pass false as a second argument if you don't want that
}

void Class::loadedRSS(QList<VNTRSSChannel*> rssChannels) {
    foreach (VNTRSSChannel* rssChannel, rssChannels) {
        if (!rssChannel->hasError()) {
            QList<VNTRSSItem*> items = rssChannel->getRSSItems();

            foreach (VNTRSSItem* item, items) {
                qDebug() << item->toString();
            }
        } else {
            qDebug() << rssChannel->getErrorMessage();
        }

        delete rssChannel;
    }
}

```

## License
GPL v2

For more information see the [LICENSE file](LICENSE).

Copyright 2014-2015 Vanniktech - Niklas Baudy