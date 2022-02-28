cmake_minimum_required(VERSION 3.21)
project(testDll)

add_executable(testDll a.cpp)

target_link_libraries(testDll  E:/Desktop/plugin_demos/cmake_link_dll/libmythread.dll) #需要给出绝对路径
