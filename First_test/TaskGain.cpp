#include "./head.h"

TaskGain::TaskGain(int k_val):SensorTaskBase(2),k(k_val){}

void TaskGain::run(){
    if(out){
        tp_out=tp_in*k;
        out=false;
    }
}

void TaskGain::stop(){
    tp_in=0;
    tp_out=0;
    out=false;
}

void TaskGain::callback(int msg){
    switch(msg){
        case 1:
            k=msg;
            break;
        case 2:
            out=true;
            break;
    }
}