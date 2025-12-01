cmake_minimum_required(VERSION 3.10)
project(First_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(app
    main.cpp
    TaskManager.cpp
    TaskDelay.cpp
    TaskGain.cpp
    TaskFilter.cpp
    SensorTaskBase.cpp
)

# 设置为控制台程序（可选，但建议）
set_property(TARGET app PROPERTY WIN_EXPORT_ALL_SYMBOLS ON)