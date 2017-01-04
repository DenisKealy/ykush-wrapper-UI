#include "sleeper.h"
#include "windows.h"

int sleepTime;

Sleeper::Sleeper()
{

}

Sleeper::Sleeper(int seconds)
{
    sleepTime = seconds;
}

void Sleeper::sleep() {
    Sleep(sleepTime*1000);
    emit wakeUp();
}
