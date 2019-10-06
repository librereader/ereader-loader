#include "SandboxedProcess.h"

#include <QtDebug>

#include <pwd.h>
#include <unistd.h>
#include <sys/stat.h>

SandboxedProcess::SandboxedProcess() :
    QProcess(), mIsSandboxed(false) { }
SandboxedProcess::~SandboxedProcess() { }

void SandboxedProcess::setupChildProcess()
{
    // Drop privileges in the child process
#if 0
    struct passwd *pw = getpwnam("squid");
    if (!pw)
        return;

    if (chdir(pw->pw_dir) < 0) {
        return;
    }

    if (setgid(pw->pw_gid) < 0) {
        return;
    }

    if (setuid(pw->pw_uid) < 0) {
        return;
    }

    umask(0022);
#else
    qDebug() << "Fake setup child process.";
#endif
    mIsSandboxed = true;
}
