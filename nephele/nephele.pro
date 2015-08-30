#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T18:40:47
#
#-------------------------------------------------

QT       += core gui script printsupport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): RC_ICONS += nephele.ico
lessThan(QT_MAJOR_VERSION, 5): RC_FILE = nephele.rc

RESOURCES += \
    Resources.qrc

TARGET = nephele
TEMPLATE = app

unix: QMAKE_CXXFLAGS += -isystem $$[QT_INSTALL_HEADERS]
unix: QMAKE_CXXFLAGS += -isystem $$[QT_INSTALL_HEADERS]/QtCore
unix: QMAKE_CXXFLAGS += -isystem $$[QT_INSTALL_HEADERS]/QtGui
unix: QMAKE_CXXFLAGS += -isystem $$[QT_INSTALL_HEADERS]/QtScript
unix: QMAKE_CXXFLAGS += -isystem $$[QT_INSTALL_HEADERS]/QtWidgets
unix: QMAKE_CXXFLAGS += -isystem '$ORIGIN'/../../../libs/qcustomplot
unix: QMAKE_CXXFLAGS += -Wall
unix: QMAKE_CXXFLAGS += -Wextra
unix: QMAKE_CXXFLAGS += -ansi
unix: QMAKE_CXXFLAGS += -pedantic
unix: QMAKE_CXXFLAGS += -Wshadow
unix: QMAKE_CXXFLAGS += -Weffc++
unix: QMAKE_CXXFLAGS += -Wstrict-aliasing

CONFIG += c++11

#message(Qt version: $$[QT_VERSION])
#message(Qt is installed in $$[QT_INSTALL_PREFIX])
#message(Qt resources can be found in the following locations:)
#message(Documentation: $$[QT_INSTALL_DOCS])
#message(Header files: $$[QT_INSTALL_HEADERS])
#message(Libraries: $$[QT_INSTALL_LIBS])
#message(Binary files (executables): $$[QT_INSTALL_BINS])
#message(Plugins: $$[QT_INSTALL_PLUGINS])
#message(Data files: $$[QT_INSTALL_DATA])
#message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
#message(Settings: $$[QT_INSTALL_SETTINGS])
#message(Examples: $$[QT_INSTALL_EXAMPLES])
#message(Demonstrations: $$[QT_INSTALL_DEMOS])


SOURCES += main.cpp\
    core/event_manager.cpp \
    script_system/scripting_worker.cpp \
    script_system/script_handler/script_act_handler.cpp \
    script_system/script_handler/script_dialoges_handler.cpp \
    script_system/script_handler/script_set_handler.cpp \
    script_system/script_handler/script_util_handler.cpp \
    gui_system/analogview.cpp \
    gui_system/flowcontrollerview.cpp \
    gui_system/nephele_main_window.cpp \
    tcp_box_system/qvmbackend.cpp \
    tcp_box_system/tcpdriver.cpp \
    tcp_box_system/tcpcommand.cpp \
    tcp_box_system/tcpcommandqueue.cpp \
    core/analogvalue.cpp \
    tcp_box_system/flowcontrollerbackend.cpp \
    script_system/script_system.cpp \
    tcp_box_system/tcp_box_system.cpp \
    gui_system/gui_system.cpp \
    gui_system/script_editor/script_editor_window.cpp \
    gui_system/script_editor/highlighter.cpp \
    gui_system/script_editor/console.cpp \
    script_system/script_handler/script_log_handler.cpp \
    core/entity_manager.cpp

HEADERS  += version.hpp \
    nephele.rc \
    core/event_manager.hpp \
    tcp_box_system/tcpcommand.hpp \
    tcp_box_system/qvmbackend.hpp \
    tcp_box_system/tcpcommandqueue.hpp \
    tcp_box_system/tcpdriver.hpp \
    gui_system/analogview.hpp \
    gui_system/flowcontrollerview.hpp \
    gui_system/nephele_main_window.hpp \
    script_system/script_handler/script_act_handler.hpp \
    script_system/script_handler/script_dialoges_handler.hpp \
    script_system/script_handler/script_set_handler.hpp \
    script_system/script_handler/script_util_handler.hpp \
    script_system/scripting_worker.hpp \
    core/analogvalue.hpp \
    tcp_box_system/flowcontrollerbackend.h \
    script_system/script_system.hpp \
    tcp_box_system/tcp_box_system.hpp \
    core/abstract_system.hpp \
    gui_system/gui_system.hpp \
    gui_system/script_editor/script_editor_window.hpp \
    gui_system/script_editor/highlighter.h \
    gui_system/script_editor/console.h \
    script_system/script_handler/script_log_handler.hpp \
    core/entity_manager.hpp \
    tcp_box_system/tcpdriverdatatypes.hpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../qcustomplot/release/ -lqcustomplot
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../qcustomplot/debug/ -lqcustomplot
else:unix: LIBS += -L$$OUT_PWD/../qcustomplot/ -lqcustomplot

INCLUDEPATH += $$PWD/../qcustomplot
DEPENDPATH += $$PWD/../qcustomplot

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../qcustomplot/release/libqcustomplot.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../qcustomplot/debug/libqcustomplot.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../qcustomplot/release/qcustomplot.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../qcustomplot/debug/qcustomplot.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../qcustomplot/libqcustomplot.a

DISTFILES += \
    nephele.ico
