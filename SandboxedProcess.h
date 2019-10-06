#if !defined(SANDBOXEDPROCESS_H)
#define SANDBOXEDPROCESS_H

#include <QProcess>

class SandboxedProcess : public QProcess
{
    Q_OBJECT
public:
    SandboxedProcess();
    ~SandboxedProcess();
signals:
    void processExitSignal();
protected:
    void setupChildProcess() override;
private:
    bool mIsSandboxed;
};

#endif
