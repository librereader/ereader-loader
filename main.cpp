#include "SandboxedProcess.h"
#include "ProcessManager.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<ProcessManager>("il.luminati", 1, 0, "ProcessManager");

    QGuiApplication app(argc, argv);
    //app.setQuitOnLastWindowClosed(false);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
