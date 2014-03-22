/*
    Copyright 2014 Vanniktech - Niklas Baudy

    This file is part of VNTRSSReader.

    VNTRSSReader is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    VNTRSSReader is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VNTRSSReader. If not, see <http://www.gnu.org/licenses/>.
*/

#include <QCoreApplication>

#include <rss.h>
#include <QTime>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QUrl url = QUrl("your_url_to_a_valid_rss_v2_service");

    RSS* rss = new RSS();
    rss->load(url, true);

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setHostName("proxy.example.com");
    proxy.setPort(1080);
    proxy.setUser("username");
    proxy.setPassword("password");

    rss->load(url, proxy);

    // we'll use this to stall our application, to get some results displayed on the console
    QTime dieTime= QTime::currentTime().addSecs(10);

    while (QTime::currentTime() < dieTime)
       QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    return 0;
}
