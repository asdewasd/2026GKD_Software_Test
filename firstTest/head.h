#ifndef HEAD_H
#define HEAD_H


#include <iostream>
#include <memory>
#include <atomic>

class SensorTaskBase{
protected:
    int key;
    int tp_in;
    int tp_out;
    std::atomic<bool> out;
public:
    SensorTaskBase(int k);
    virtual ~SensorTaskBase()=default;
    virtual void run()=0;
    virtual void stop()=0;
    virtual void callback(int msg)=0;

    int getKey() const;

    void setTpIn(int val);
    void setTpOut(int val);
    int getTpIn() const;
    int getTpOut() const;

    void setOut(bool val);
    bool getOut() const;
};

#endif