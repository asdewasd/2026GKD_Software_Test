#include "head.h"

TaskDelay::TaskDelay():SensorTaskBase(3),prev_val(0){}

void TaskDelay::run(){
    if(out){
        tp_out=prev_val;
        prev_val=tp_in;
        out=false;
    }       
}

void TaskDelay::stop(){
    tp_in=0;
    tp_out=0;
    prev_val=0;
    out=false;          
}

void TaskDelay::callback(int msg){
    switch(msg){
        case 1:
            prev_val=msg;
            break;
        case 2:
            out=true;
            break;      
    }
}