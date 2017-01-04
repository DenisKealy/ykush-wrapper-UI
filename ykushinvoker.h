#ifndef YKUSHINVOKER_H
#define YKUSHINVOKER_H


class YkushInvoker {

public:
    YkushInvoker();
    void timedBurst(int portNo, int seconds);
    void powerDownAll();

private:

    void powerUpPort(int portNo);
    void powerDownPort(int portNo);

};

#endif // YKUSHINVOKER_H
