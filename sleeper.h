#ifndef SLEEPER_H
#define SLEEPER_H
#include "QObject"


class Sleeper : public QObject {
    Q_OBJECT

public:
    Sleeper();
    Sleeper(int seconds);

public slots:
    void sleep();

signals:
    void wakeUp();
};

#endif // SLEEPER_H
