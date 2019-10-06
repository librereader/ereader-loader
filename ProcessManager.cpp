#include "ProcessManager.h"

#include <QDebug>
#include <QEventLoop>

ProcessManager::ProcessManager(QObject *parent):
    QObject(parent)
{
    Q_ASSERT(connect(&mProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &ProcessManager::finished));
    // Doesn't work
    // emit mProcess.finished(0, QProcess::NormalExit);
}

void ProcessManager::run()
{
    if (mCommand.isEmpty())
        return;

    mProcess.start(mCommand);
    if (!mProcess.waitForStarted(1000)) {
        qDebug() << "Starting process failed or timed out (1000ms)";
        return;
    }

    // Works
#if 1
    // Since QML is calling from a separate thread without an
    // event loop we need to add our own.
    QEventLoop loop;
    connect(&mProcess, QOverload<int>::of(&QProcess::finished), &loop, &QEventLoop::quit);
    loop.exec();
    emit finished(0, QProcess::NormalExit);
#endif
    // Works
#if 0
    mProcess.waitForFinished(-1);
    qDebug() << "Wait for finshed";
    emit finished(0, QProcess::NormalExit);
#endif
}
