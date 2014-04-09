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

#ifndef VNTRSSITEM_H
#define VNTRSSITEM_H

#include <QString>

#include <vntrsscommon.h>

class VNTRSSItem : public VNTRSSCommon {
public:
    VNTRSSItem(QString link, QString title, QString description, QString pubDate, QString category, QString guid, QString imageUrl);

    QString getGuid() const;
    QString getCategory() const;

    QString toString() const;

private:
    QString mGuid;
    QString mCategory;
};

#endif // VNTRSSITEM_H
