include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../Lab9_Project_for_tests/IKeypad.h \
        ../Lab9_Project_for_tests/ILatch.h \
        ../Lab9_Project_for_tests/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../Lab9_Project_for_tests/lockcontroller.cpp \
        _test.cc \
        main.cpp
