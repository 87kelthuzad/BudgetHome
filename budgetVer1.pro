TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    budget.cpp \
    interface.cpp \
    transaction.cpp \
    manage.cpp \
    localtime.cpp

HEADERS += \
    budget.h \
    interface.h \
    transaction.h \
    manage.h \
    exception.h \
    localtime.h
