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
#include <vntrssreader.h>
#include <vntrsschannel.h>

public slots:
    void loadedRSS(VNTRSSChannel* rssChannel, QString errorMessage);

private:
    VNTRSSReader* mRSSReader;
```

**Class.cpp**
```
Class::Class() {
	mRSSReader = new VNTRSSReader();
	QObject::connect(mRSSReader, SIGNAL(loadedRSS(VNTRSSChannel*, QString)), this, SLOT(loadedRSS(VNTRSSChannel*, QString)));	
}

void Class::loadRSS() {
	// Now you can either load them via the system proxy or specify a proxy
	QUrl url = QUrl("your_url_to_a_valid_rss_v2_service");
	mRSSReader->load(url, true); // will use system proxy

	QNetworkProxy proxy;
	proxy.setType(QNetworkProxy::Socks5Proxy);
	proxy.setHostName("proxy.example.com");
	proxy.setPort(1080);
	proxy.setUser("username");
	proxy.setPassword("password");
	mRSSReader->load(url, proxy);
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