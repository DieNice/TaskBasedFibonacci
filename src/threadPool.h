#ifndef TASKBASEDPARALLELISM_THREADPOOL_H
#define TASKBASEDPARALLELISM_THREADPOOL_H

#include "taskQueue.h"
#include <thread>

class ThreadPool {
    std::vector<std::thread> threads;
    TaskQueue *queue;

    static void thread_proc(TaskQueue *q);

public:
    ThreadPool(TaskQueue *q, unsigned thread_count);

    void terminate();

};


#endif //TASKBASEDPARALLELISM_THREADPOOL_H
