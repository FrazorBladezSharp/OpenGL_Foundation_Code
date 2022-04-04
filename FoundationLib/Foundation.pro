
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c17 c++17

INCLUDEPATH += .
INCLUDEPATH += ./Source

LIBS += -lGL

SOURCES +=  \
    Source/Amberskies/Core/Application.cpp

HEADERS +=  \
    Source/Amberskies.h \
    Source/Amberskies/Core/Application.h \
    Source/Amberskies/Core/MainEntryPoint.h \
    Source/Common.h

DISTFILES += 
