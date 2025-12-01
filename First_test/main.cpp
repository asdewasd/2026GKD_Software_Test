#include "./head.h"

int main(){
    TaskManager manager;
    manager.addTask(std::unique_ptr<SensorTaskBase>(new Taskfilter(5)));
    manager.addTask(std::unique_ptr<SensorTaskBase>(new TaskGain(2)));
    manager.addTask(std::unique_ptr<SensorTaskBase>(new TaskDelay()));
    manager.callback(1, 2);
    manager.runAllTasks();
    std::cout << "Task count: " << manager.getTaskCount() << std::endl;
    return 0;
}