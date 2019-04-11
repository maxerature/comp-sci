TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    converter.cpp \
    converteru_a.cpp \
    ConverterU_B.cpp \
    ConverterU_C.cpp \
    ConverterU_D.cpp \
    ConverterU_E.cpp \
    ConverterU_F.cpp \
    ConverterU_G.cpp

HEADERS += \
    converter.h \
    converteru_a.h \
    ConverterU_B.h \
    ConverterU_C.h \
    ConverterU_D.h \
    ConverterU_E.h \
    ConverterU_F.h \
    ConverterU_G.h

SUBDIRS += \
    HW7.pro

DISTFILES +=
