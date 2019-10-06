#include "ProcessManager.h"

#include <QDebug>

ProcessManager::ProcessManager(QObject *parent):
    QObject(parent)
{
    Q_ASSERT(connect(&mProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &ProcessManager::finished));
    qDebug() << "Connected successfully";
    // Doesn't work
    // emit mProcess.finished(0, QProcess::NormalExit);
}

void ProcessManager::run()
{
    if (!mCommand.isEmpty())
        mProcess.execute(mCommand);

    // Works
#if 1
    mProcess.waitForFinished(-1);
    qDebug() << "Wait for finshed";
    emit finished(0, QProcess::NormalExit);
#endif
}
