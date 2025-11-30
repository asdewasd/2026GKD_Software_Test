#include "./head.h"

SensorTaskBase::SensorTaskBase(int k):key(k),tp_in(0),tp_out(0),out(false){}

int SensorTaskBase::getKey() const{return key;}

void SensorTaskBase::setTpIn(int val){tp_in=val;}
void SensorTaskBase::setTpOut(int val){tp_out=val;}
int SensorTaskBase::getTpIn() const{return tp_in;}
int SensorTaskBase::getTpOut() const{return tp_out;}

void SensorTaskBase::setOut(bool val){out=val;}
bool SensorTaskBase::getOut() const{return out;}