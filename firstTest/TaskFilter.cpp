#include "head.h"

TaskFilter::TaskFilter(int th):SensorTaskBase(1),threshold(th){}

void TaskFilter::run(){
    if(out){
        if(tp_in>threshold){
            tp_out=tp_in;
        }
        else{
            tp_out=0;
        }
        out=false;
    }
}

void TaskFilter::stop(){
    tp_out=0;
    tp_in=0;
    out=false;
}

void TaskFilter::callback(int msg){
    switch(msg){
        case 1:
            threshold=msg;
            break;
        case 2:
            out=true;
            break;
    }
}