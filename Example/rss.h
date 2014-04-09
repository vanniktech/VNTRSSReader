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

#ifndef RSS_H
#define RSS_H

#include <QObject>

#include <vntrssreader.h>
#include <vntrsschannel.h>

class RSS : public QObject {
    Q_OBJECT
public:
    explicit RSS(QObject *parent = 0);
    ~RSS();

    void load(QUrl url);

public slots:
    void loadedRSS(QList<VNTRSSChannel*> rssChannels, QString errorMessage);

private:
    VNTRSSReader* mRSSReader;

};

#endif // RSS_H
