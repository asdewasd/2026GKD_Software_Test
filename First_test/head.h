#ifndef GDK_H
#define GDK_H

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <atomic>
#include <algorithm>

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

class Taskfilter:public SensorTaskBase{ 
private:
    int threshold;
public:
    Taskfilter(int th);

    void run() override;
    void stop() override;
    void callback(int msg) override;
};

class TaskGain:public SensorTaskBase{
private:
    int k;
public:
    TaskGain(int k_val);

    void run() override;
    void stop() override;
    void callback(int msg) override;
};

class TaskDelay:public SensorTaskBase{
private:
    int prev_val;
public:
    TaskDelay();

    void run() override;
    void stop() override;
    void callback(int msg) override;
};

class TaskManager{
private:
    std::vector<std::unique_ptr<SensorTaskBase>> tasks;
public:
    void addTask(std::unique_ptr<SensorTaskBase> task);
    void removeTask(int key);
    void runAllTasks();
    void stopAllTasks();
    void callback(int key,int msg);
    size_t getTaskCount() const;
    bool hasTask(int key) const;
};

#endif // GDK_H