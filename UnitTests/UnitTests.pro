#-------------------------------------------------
# Copyright 2014 Vanniktech - Niklas Baudy
#
# This file is part of SpeedReader.
#
# SpeedReader is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# SpeedReader is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with SpeedReader. If not, see <http://www.gnu.org/licenses/>.
#-------------------------------------------------

QT += testlib network
TEMPLATE = app
TARGET = UnitTests
INCLUDEPATH += .

SOURCES += unittests.cpp ../VNTRSSReader/vntrssreader.cpp \
    ../VNTRSSReader/vntprotocolhandler.cpp\
    ../VNTRSSReader/vntrssitem.cpp \
    ../VNTRSSReader/vntrsschannel.cpp\
    ../VNTRSSReader/vntrsshandler.cpp\
    ../VNTRSSReader/vntatomhandler.cpp\
    ../VNTRSSReader/vntrsscommon.cpp

HEADERS += ../VNTRSSReader/vntrssreader.h\
    ../VNTRSSReader/vntrssreader_global.h \
    ../VNTRSSReader/vntprotocolspecialcase.h\
    ../VNTRSSReader/vntprotocolhandler.h\
    ../VNTRSSReader/vntrssitem.h \
    ../VNTRSSReader/vntrsschannel.h\
    ../VNTRSSReader/vntrsshandler.h\
    ../VNTRSSReader/vntatomhandler.h\
    ../VNTRSSReader/vntrsscommon.h
