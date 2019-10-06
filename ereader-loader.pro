TEMPLATE = app
TARGET = ereader-loader
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

QT += quick quickcontrols2

RESOURCES += qml.qrc

SOURCES += main.cpp \
            ProcessManager.cpp \
            SandboxedProcess.cpp

HEADERS +=  ProcessManager.h \
            SandboxedProcess.h
