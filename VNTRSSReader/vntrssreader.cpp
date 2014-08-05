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

#include <QXmlStreamReader>
#include <QImageReader>

#include "vntrssreader.h"

VNTRSSReader::VNTRSSReader(QObject *parent) : QObject(parent) {
    mNetworkAccessManager = new QNetworkAccessManager(this);
    QObject::connect(mNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    mNetworkAccessManagerImages = new QNetworkAccessManager(this);
    QObject::connect(mNetworkAccessManagerImages, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinishedImages(QNetworkReply*)));
}

VNTRSSReader::~VNTRSSReader() {
    delete mNetworkAccessManager;
    delete mNetworkAccessManagerImages;
}

void VNTRSSReader::load(QUrl url) {
    this->load(url, true);
}

void VNTRSSReader::load(QUrl url, bool loadImages) {
    mLoadImages = loadImages;
    mMissingChannels = 1;
    mNetworkAccessManager->get(QNetworkRequest(url));
}

void VNTRSSReader::load(QList<QUrl> urls) {
    this->load(urls, true);
}

void VNTRSSReader::load(QList<QUrl> urls, bool loadImages) {
    mLoadImages = loadImages;
    mMissingChannels = urls.size();
    foreach (QUrl url, urls) mNetworkAccessManager->get(QNetworkRequest(url));
}

void VNTRSSReader::replyFinished(QNetworkReply* networkReply) {
    QXmlStreamReader xmlReader(networkReply->readAll());
    QString name;

    mMissingChannels -= 1;

    VNTRSSChannel* rssChannel = NULL;
    VNTRSSItem* rssItem = NULL;

    QHash<QString, QString> functionValueHash;
    bool rss, atom;

    for (int i = 0; !xmlReader.atEnd() && !xmlReader.hasError();) {
        xmlReader.readNext();
        name = xmlReader.name().toString();

        if (xmlReader.isStartDocument()) {
            rssChannel = new VNTRSSChannel();

            if (xmlReader.hasError()) {
                rssChannel->setErrorMessage(tr("Could not retrieve a valid XML response from %1").arg(networkReply->url().toString()));
                break;
            }
        }

        if (xmlReader.isStartElement()) {
            if (i++ == 0) { // Root Element
                rss = name == "rss";
                atom = name == "feed";

                if (!(rss || atom)) {
                    rssChannel->setErrorMessage(QString("%1 %2").arg(networkReply->url().toString(), tr("is not a valid RSS feed")));
                    break;
                }
            }

            if ((name == "item" || name == "entry") && rssChannel != NULL) {
                rssItem = new VNTRSSItem();
                rssChannel->addItem(rssItem);
            }

            QString prefix = xmlReader.prefix().toString();

            if (prefix == "dc" || (prefix == "media" && name == "title") || (prefix == "atom10" && name == "link")) continue;
            else if (atom && (name == "summary" || name == "subtitle")) name = "description";
            else if (atom && (name == "published" || name == "updated")) name = "pubDate";
            else if (atom && name == "id") name = "guid";
            else if (prefix == "media" && name == "thumbnail") name = "imageUrl";

            QString functionName = QString("set%1%2").arg(name.at(0).toUpper(), name.mid(1));
            const char* functionNameWithParameter = functionName.mid(0).append("(QString)").toStdString().c_str();

            if (rssChannel->metaObject()->indexOfMethod(functionNameWithParameter) != -1 || (rssItem != NULL && rssItem->metaObject()->indexOfMethod(functionNameWithParameter) != -1)) {
                QString value;

                if (name == "link" && atom) value = xmlReader.attributes().value("href").toString();
                else if (prefix == "media" && name == "imageUrl") value = xmlReader.attributes().value("url").toString();
                else value = xmlReader.readElementText();

                functionValueHash.insert(functionName, value);
            }
        } else if (xmlReader.isEndElement()) {
            if (rssChannel != NULL && rssItem == NULL) {
                QHashIterator<QString, QString> it(functionValueHash);
                while (it.hasNext()) {
                    it.next();
                    QMetaObject::invokeMethod(rssChannel, it.key().toStdString().c_str(), Qt::DirectConnection, Q_ARG(QString, it.value()));
                }

                functionValueHash.clear();
            } else if (rssItem != NULL) {
                QHashIterator<QString, QString> it(functionValueHash);
                while (it.hasNext()) {
                    it.next();
                    QMetaObject::invokeMethod(rssItem, it.key().toStdString().c_str(), Qt::DirectConnection, Q_ARG(QString, it.value()));
                }

                functionValueHash.clear();
            }
        }
    }

    rssChannel->setRSSUrl(networkReply->url());
    foreach (VNTRSSItem* item, rssChannel->getItems()) this->loadImage(item);
    mRSSChannels.append(rssChannel);
    this->loadImage(rssChannel);

    this->fireEmitIfDone();

    delete networkReply;
}

void VNTRSSReader::replyFinishedImages(QNetworkReply* networkReply) {
    QList<VNTRSSCommon*> commons = mUrlItemMultiMap.values(networkReply->url());
    QImage image = QImageReader(networkReply).read();

    foreach (VNTRSSCommon* common, commons) common->setImage(image);

    mUrlItemMultiMap.remove(networkReply->url());

    this->fireEmitIfDone();

    delete networkReply;
}

void VNTRSSReader::loadImage(VNTRSSCommon* common) {
    if (mLoadImages && !common->getImageUrl().isEmpty()) {
        if (mUrlItemMultiMap.values(common->getImageUrl()).size() == 0) mNetworkAccessManagerImages->get(QNetworkRequest(common->getImageUrl()));
        mUrlItemMultiMap.insert(common->getImageUrl(), common);
    }
}

void VNTRSSReader::fireEmitIfDone() {
    if (mUrlItemMultiMap.size() == 0 && mMissingChannels == 0) {
        emit loadedRSS(mRSSChannels);
        mRSSChannels.clear();
    }
}
