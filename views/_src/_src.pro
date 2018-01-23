TARGET = view
TEMPLATE = lib
CONFIG += shared c++11
QT += network xml sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../../lib
INCLUDEPATH += ../../helpers ../../models ../../controllers
DEPENDPATH  += ../../helpers ../../models ../../controllers
LIBS += -L../../lib -lhelper -lmodel -lcontroller
QMAKE_CLEAN = *.cpp *.moc *.o source.list

tmake.target = source.list
tmake.commands = tmake -f ../../config/application.ini -v .. -d . -P
tmake.depends = qmake_all

QMAKE_EXTRA_TARGETS = tmake
POST_TARGETDEPS = source.list

include(../../appbase.pri)
!exists(source.list) {
  system( $$tmake.commands )
}
include(source.list)
