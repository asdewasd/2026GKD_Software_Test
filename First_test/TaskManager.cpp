#include "./head.h"

void TaskManager::addTask(std::unique_ptr<SensorTaskBase> task){
    tasks.push_back(std::move(task));
}

void TaskManager::removeTask(int key){
    tasks.erase(std::remove_if(tasks.begin(),tasks.end(),
        [key](const std::unique_ptr<SensorTaskBase>& task){
            return task->getKey()==key;
    }),tasks.end());
}

void TaskManager::runAllTasks(){
    for(auto& task:tasks){
        task->run();
    }
}

void TaskManager::stopAllTasks(){
    for(auto& task:tasks){
        task->stop();
    }
}

void TaskManager::callback(int key,int msg){
    for(auto& task:tasks){
        if(task->getKey()==key){
            task->callback(msg);
            break;
        }
    }
}

size_t TaskManager::getTaskCount() const{
    return tasks.size();
}

bool TaskManager::hasTask(int key) const{
    return std::find_if(tasks.begin(),tasks.end(),
        [key](const std::unique_ptr<SensorTaskBase>& task){
            return task->getKey()==key;
    })!=tasks.end();
}