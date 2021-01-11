#ifndef TASKBASEDPARALLELISM_TASKQUEUE_H
#define TASKBASEDPARALLELISM_TASKQUEUE_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include "task.h"
#include <queue>

class TaskQueue {
    std::queue<Task *> q;
    std::mutex mtx;
    std::condition_variable cvEmpty, cvNotEmpty;
public:
    void push_task(Task *tsk);

    Task *pop_task();

    void clr();

    void wait_until_empty();

};


#endif //TASKBASEDPARALLELISM_TASKQUEUE_H
