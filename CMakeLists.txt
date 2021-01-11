cmake_minimum_required(VERSION 3.17)
project(TaskBasedParallelism)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskBasedParallelism main.cpp src/control_state.h src/control_state_fib_async.cpp
        src/control_state_fib_async.h src/control_state_fib_blocking.cpp src/control_state_fib_blocking.h src/loadBalancer.cpp
        src/loadBalancer.h src/task.h src/task_fib.cpp src/task_fib.h src/threadPool.cpp src/threadPool.h src/taskQueue.h src/taskQueue.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")