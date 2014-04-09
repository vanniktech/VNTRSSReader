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

#include "vntrsschannel.h"

VNTRSSChannel::VNTRSSChannel(QString link, QString title, QString description, QString pubdate, QString language, QString copyright, QString imageUrl, QUrl rssUrl, QList<VNTRSSItem*> items) : VNTRSSCommon(title, description, pubdate, link, imageUrl) {
    mLanguage = language.simplified();
    mCopyright = copyright.simplified();
    mRSSUrl = rssUrl;
    mItems = items;
}

VNTRSSChannel::~VNTRSSChannel() {
    foreach (VNTRSSItem* item, mItems) delete item;
}

QString VNTRSSChannel::getLanguage() const {
    return mLanguage;
}

QString VNTRSSChannel::getCopyright() const {
    return mCopyright;
}

QUrl    VNTRSSChannel::getRSSUrl() const {
    return mRSSUrl;
}

QList<VNTRSSItem*> VNTRSSChannel::getItems() const {
    return mItems;
}

QString VNTRSSChannel::toString() const {
    return VNTRSSCommon::toString().append(QString("language=%1\ncopyright=%2\nrssurl=%3").arg(mLanguage, mCopyright, mRSSUrl.toString()));
}
