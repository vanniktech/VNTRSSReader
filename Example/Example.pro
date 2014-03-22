#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T17:55:44
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

QT       += core
QT       += network

QT       -= gui

OBJECTS_DIR = .obj
MOC_DIR     = .moc
RCC_DIR     = .rcc

TARGET = Example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH = ../VNTRSSReader/

SOURCES += main.cpp \
    rss.cpp

HEADERS += \
    rss.h
