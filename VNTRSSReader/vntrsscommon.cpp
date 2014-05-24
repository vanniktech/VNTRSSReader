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

#include <QRegExp>
#include <QStringList>

#include "vntrsscommon.h"

VNTRSSCommon::VNTRSSCommon(QString title, QString description, QString pubDate, QUrl link, QUrl imageUrl) {
    mTitle = title.simplified();
    mDescription = description.simplified();

    QString pubDateFormatted = pubDate.simplified();
    pubDateFormatted = pubDateFormatted.mid(5); // replace weekday (e.g.:Thu, )

    if (pubDateFormatted.length() == 26) pubDateFormatted = pubDateFormatted.remove(pubDateFormatted.length() - 6, 6); // replace timezone (e.g.: +0200)
    else if (pubDateFormatted.length() == 24) pubDateFormatted = pubDateFormatted.remove(pubDateFormatted.length() - 4, 4); // replace timezone (e.g.: GMT)

    // need to do this, because month have different abbreviations on different operating systems with different languages
    pubDateFormatted = pubDateFormatted.replace("Jan", "01");
    pubDateFormatted = pubDateFormatted.replace("Feb", "02");
    pubDateFormatted = pubDateFormatted.replace("Mar", "03");
    pubDateFormatted = pubDateFormatted.replace("Apr", "04");
    pubDateFormatted = pubDateFormatted.replace("May", "05");
    pubDateFormatted = pubDateFormatted.replace("Jun", "06");
    pubDateFormatted = pubDateFormatted.replace("Jul", "07");
    pubDateFormatted = pubDateFormatted.replace("Aug", "08");
    pubDateFormatted = pubDateFormatted.replace("Sep", "09");
    pubDateFormatted = pubDateFormatted.replace("Oct", "10");
    pubDateFormatted = pubDateFormatted.replace("Nov", "11");
    pubDateFormatted = pubDateFormatted.replace("Dez", "12");

    mPubDate = QDateTime::fromString(pubDateFormatted, "dd MM yyyy HH:mm:ss");

    mLink = link;
    mImageUrl = imageUrl;
    this->updateImageFileType();
}

QString VNTRSSCommon::getTitle() const {
    return mTitle;
}

QString VNTRSSCommon::getDescription() const {
    return mDescription;
}

QString VNTRSSCommon::getPlainDescription() {
    return mDescription.remove(QRegExp("<[^>]*>")).simplified();
}

QDateTime VNTRSSCommon::getPubDate() const {
    return mPubDate;
}

QUrl VNTRSSCommon::getLink() const {
    return mLink;
}

QUrl VNTRSSCommon::getImageUrl() const {
    return mImageUrl;
}

QString VNTRSSCommon::getImageFileType() const {
    return mImageFileType;
}

QImage VNTRSSCommon::getImage() const {
    return mImage;
}

void VNTRSSCommon::setImage(const QImage &value) {
    mImage = value;
}

QString VNTRSSCommon::toString() const {
    return QString("\nlink=%1\ntitle=%2\ndescription=%3\npubDate=%4\nimageUrl=%5").arg(mLink.toString(), mTitle, mDescription, mPubDate.toString(), mImageUrl.toString());
}

void VNTRSSCommon::updateImageFileType() {
    mImageFileType = mImageUrl.toString().split(".").last();
}
