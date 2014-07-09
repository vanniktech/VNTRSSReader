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

#ifndef VNTRSSCHANNEL_H
#define VNTRSSCHANNEL_H

#include <QString>
#include <QList>
#include <QUrl>

#include "vntrssitem.h"
#include "vntrsscommon.h"

class VNTRSSChannel : public VNTRSSCommon {
    Q_OBJECT

public:
    VNTRSSChannel();
    ~VNTRSSChannel();

    Q_INVOKABLE void setLanguage(QString language);
    QString getLanguage() const;

    Q_INVOKABLE void setCopyright(QString copyright);
    QString getCopyright() const;

    void setRSSUrl(QUrl rssUrl);
    QUrl getRSSUrl() const;

    void setErrorMessage(QString errorMessage);
    QString getErrorMessage() const;
    bool hasError() const;

    void addItem(VNTRSSItem* item);
    QList<VNTRSSItem *> getItems() const;

    QString toString() const;

private:
    QString mLanguage;
    QString mCopyright;
    QUrl    mRSSUrl;
    QString mErrorMessage;
    QList<VNTRSSItem*> mItems;
};

#endif // VNTRSSCHANNEL_H
