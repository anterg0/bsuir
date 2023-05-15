QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../MyString/mystring.h \
    mainwindow.h \
    mystring.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/release/ -lMyString.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/debug/ -lMyString.1.0.0
else:unix: LIBS += -L$$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/ -lMyString.1.0.0

INCLUDEPATH += $$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug
DEPENDPATH += $$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/release/ -lMyString.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/debug/ -lMyString.1.0.0
else:unix: LIBS += -L$$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/ -lMyString.1.0.0

INCLUDEPATH += $$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug
DEPENDPATH += $$PWD/../build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../ОАИП/sem2/lab4/build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/release/ -lMyString.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../ОАИП/sem2/lab4/build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/debug/ -lMyString.1.0.0
else:unix: LIBS += -L$$PWD/../../../../ОАИП/sem2/lab4/build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug/ -lMyString.1.0.0

INCLUDEPATH += $$PWD/../../../../ОАИП/sem2/lab4/build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug
DEPENDPATH += $$PWD/../../../../ОАИП/sem2/lab4/build-MyString-Desktop_x86_darwin_generic_mach_o_64bit-Debug
