#-------------------------------------------------
#
# Project created by QtCreator 2012-11-03T15:12:12
#
#-------------------------------------------------

QT       += core gui sql webkit network

TARGET = wordbook
TEMPLATE = app


SOURCES += main.cpp\
        database.cpp\
        lineedit.cpp \
    wordbookdock.cpp

HEADERS  += database.h\
        lineedit.h \
    wordbookdock.h

INCLUDEPATH += ../build
INCLUDEPATH += ..

FORMS    += wordbook.ui \
    wordbookdock.ui
