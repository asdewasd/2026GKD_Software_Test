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

class TaskFilter: public SensorTaskBase{
    private:
        int threshold;
    public:
        TaskFilter(int key);

        void run()override;
        void stop()override;
        void callback(int msg)override;
};

class TaskGain: public SensorTaskBase{
    private:
        int k;
    public:
        TaskGain(int k_val);

        void run()override;
        void stop()override;
        void callback(int msg)override;
};

class TaskDelay: public SensorTaskBase{
    private:
        int prev_val;
    public:
        TaskDelay();

        void run()override;
        void stop()override;
void callback(int msg)override; 
};
#endif