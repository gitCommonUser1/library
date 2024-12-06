QT += core network sql

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        imagereceiver.cpp \
        main.cpp \
        messageio.cpp \
        server.cpp \
        sql.cpp


LIBS += -lws2_32


## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

HEADERS += \
    crc16.h \
    imagereceiver.h \
    messagecmd.h \
    messageio.h \
    server.h \
    sql.h
