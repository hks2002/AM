TEMPLATE = app
CONFIG += console debug
CONFIG -= app_bundle
QT += network sql xml testlib
QT -= gui
DEFINES += TF_DLL
INCLUDEPATH += ../../
LIBS += -L../../lib -lmodel -lcontroller -lhelper

win32 {
  INCLUDEPATH += $$quote($$(TFDIR)\\include)
  LIBS += -L$$quote($$(TFDIR)\\bin)

  CONFIG(debug, debug|release) {
    LIBS += -ltreefrogd1
  } else {
    LIBS += -ltreefrog1
  }
} else {
  unix:LIBS += -Wl,-rpath,. -Wl,-rpath,/usr/lib -L/usr/lib -ltreefrog
  unix:INCLUDEPATH += /usr/include/treefrog

  # c++11
  lessThan(QT_MAJOR_VERSION, 5) {
    QMAKE_CXXFLAGS += -std=c++0x
  }
}
