#ifndef TASKBASEDPARALLELISM_LOADBALANCER_H
#define TASKBASEDPARALLELISM_LOADBALANCER_H

#include "task.h"
#include "threadPool.h"
#include <thread>
#include "taskQueue.h"

class LoadBalancer {

private:
    ThreadPool pool;
    TaskQueue q;
public:

    LoadBalancer(unsigned thread_count = std::thread::hardware_concurrency()) : pool(&q, thread_count) {}

    ~LoadBalancer();

    void add_task(Task *);


};


static LoadBalancer lb;

#endif //TASKBASEDPARALLELISM_LOADBALANCER_H
