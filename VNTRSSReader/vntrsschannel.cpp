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

VNTRSSChannel::VNTRSSChannel() : VNTRSSCommon() {

}

VNTRSSChannel::~VNTRSSChannel() {
    qDeleteAll(mItems.begin(), mItems.end());
}

void VNTRSSChannel::setLanguage(QString language) {
    mLanguage = language.simplified();
 }

QString VNTRSSChannel::getLanguage() const {
    return mLanguage;
}

void VNTRSSChannel::setCopyright(QString copyright) {
    mCopyright = copyright.simplified();
}

QString VNTRSSChannel::getCopyright() const {
    return mCopyright;
}

void VNTRSSChannel::setRSSUrl(QUrl rssUrl) {
    mRSSUrl = rssUrl;
}

QUrl VNTRSSChannel::getRSSUrl() const {
    return mRSSUrl;
}

void VNTRSSChannel::setErrorMessage(QString errorMessage) {
    mErrorMessage = errorMessage;
}

QString VNTRSSChannel::getErrorMessage() const {
    return mErrorMessage;
}

bool VNTRSSChannel::hasError() const {
    return !mErrorMessage.isEmpty();
}

void VNTRSSChannel::addItem(VNTRSSItem* item) {
    mItems.append(item);
}

QList<VNTRSSItem*> VNTRSSChannel::getItems() const {
    return mItems;
}

QString VNTRSSChannel::toString() const {
    return VNTRSSCommon::toString().append(QString("\nlanguage=%1\ncopyright=%2\nrssurl=%3\nerrormessage=%4").arg(mLanguage, mCopyright, mRSSUrl.toString(), mErrorMessage));
}
