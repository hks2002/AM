TEMPLATE = subdirs
CONFIG  += testcase

SUBDIRS  += dataservice
SUBDIRS  += helper

amtests.target = test
amtests.commands = make check
QMAKE_EXTRA_TARGETS += amtests
