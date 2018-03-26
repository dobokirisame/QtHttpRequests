DEFINES += QHTTPREQUESTS_LIBRARY
include (src.pri)
TEMPLATE = lib
TARGET = QHttpRequests
USE_USER_DESTDIR = YES

QT += network

DISTFILES += *.pri

SOURCES += *cpp

HEADERS +=*.h
