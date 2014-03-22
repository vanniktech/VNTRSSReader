#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T17:25:28
#
#-------------------------------------------------

#-------------------------------------------------
# Copyright 2014 Vanniktech - Niklas Baudy
#
# This file is part of VNTRSSReader.
#
# VNTRSSReader is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# VNTRSSReader is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with VNTRSSReader. If not, see <http://www.gnu.org/licenses/>.
#-------------------------------------------------

QT       += network

QT       -= gui

OBJECTS_DIR = .obj
MOC_DIR     = .moc
RCC_DIR     = .rcc

TARGET = VNTRSSReader
TEMPLATE = lib

DEFINES += VNTRSSREADER_LIBRARY

SOURCES += vntrssreader.cpp \
    vntrssitem.cpp \
    vntrsschannel.cpp

HEADERS += vntrssreader.h\
        vntrssreader_global.h \
    vntrssitem.h \
    vntrsschannel.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
