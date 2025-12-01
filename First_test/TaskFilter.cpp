#include "./head.h"

Taskfilter::Taskfilter(int th):SensorTaskBase(1),threshold(th){}

void Taskfilter::run(){
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

void Taskfilter::stop(){
    tp_in=0;
    tp_out=0;
    out=false;
}

void Taskfilter::callback(int msg){
    switch(msg){
        case 1:
            threshold=msg;
            break;
        case 2:
            out=true;
            break;
    }
}