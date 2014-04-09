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

#include "rss.h"

#include <QDebug>

RSS::RSS(QObject *parent) : QObject(parent) {
    mRSSReader = new VNTRSSReader();
    QObject::connect(mRSSReader, SIGNAL(loadedRSS(QList<VNTRSSChannel*>, QString)), this, SLOT(loadedRSS(QList<VNTRSSChannel*>, QString)));
}

RSS::~RSS() {
    delete mRSSReader;
}

void RSS::load(QUrl url) {
    mRSSReader->load(url); // will automatically download the images. pass false as a second argument if you don't want that
}

void RSS::loadedRSS(QList<VNTRSSChannel*> rssChannels, QString errorMessage) {
    foreach (VNTRSSChannel* rssChannel, rssChannels) {
        if (errorMessage.isEmpty()) {
            QList<VNTRSSItem*> items = rssChannel->getItems();
            foreach (VNTRSSItem* item, items) qDebug() << item->toString();
        } else qDebug() << errorMessage;

        delete rssChannel;
    }
}
