#if !defined(PROCESSMANAGER_H)
#define PROCESSMANAGER_H

#include "SandboxedProcess.h"

class ProcessManager : public QObject
{
    Q_OBJECT
public:
    ProcessManager(QObject *parent=nullptr);
    Q_INVOKABLE void run();
    Q_PROPERTY(QString command READ command WRITE setCommand);
    void setCommand(const QString &c) {
        mCommand = c;
    }
    QString command() const {
        return mCommand;
    }
signals:
    void readySignal(int exitCode, QProcess::ExitStatus exitStatus);
private:
    QString mCommand;
    SandboxedProcess mProcess;
};

#endif
