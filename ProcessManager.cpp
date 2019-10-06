#include "ProcessManager.h"

#include <QDebug>
#include <QEventLoop>

ProcessManager::ProcessManager(QObject *parent):
    QObject(parent)
{
    const bool connected = connect(&mProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &ProcessManager::finished);

    Q_ASSERT(connected);
    Q_UNUSED(connected);
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
}
