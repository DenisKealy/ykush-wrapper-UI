#include "ykushinvoker.h"
#include "windows.h"
#include <string>
#include <QtCore/QThread>
#include <QCoreApplication>
#include "sleeper.h"


STARTUPINFO si = { sizeof(STARTUPINFO) };
PROCESS_INFORMATION pi;
std::string path =  "C:\\ykush\\ykushcmd.exe ";

YkushInvoker::YkushInvoker()
{

    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

}

void YkushInvoker::powerUpPort(int portNo){

    std::string commandLineArgs("-u ");
    std::string portNoStr = std::to_string(portNo);
    commandLineArgs = commandLineArgs + portNoStr;

    std::string command = path + commandLineArgs + portNoStr;

    system(command.c_str());
}

void YkushInvoker::powerDownPort(int portNo){

    std::string commandLineArgs("-d ");
    std::string portNoStr = std::to_string(portNo);
    commandLineArgs = commandLineArgs + portNoStr;

    std::string command = path + commandLineArgs + portNoStr;

    system(command.c_str());
}

void YkushInvoker::powerDownAll(){

    std::string commandLineArgs("-d ");
    std::string portNoStr = "a";
    commandLineArgs = commandLineArgs + portNoStr;

    std::string command = path + commandLineArgs + portNoStr;

    system(command.c_str());
}


void YkushInvoker::timedBurst(int portNo, int seconds) {


    powerUpPort(portNo);

    QThread* thread = new QThread;
    Sleeper* sleeper = new Sleeper(seconds);
    sleeper->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()), sleeper, SLOT(sleep()));
    QObject::connect(sleeper, SIGNAL(wakeUp()), thread, SLOT(quit()));
    thread->start();

    while (thread->isRunning())
    {
        QCoreApplication::processEvents();
    }

    powerDownPort(portNo);

}




