#ifndef TASKBASEDPARALLELISM_TASK_FIB_H
#define TASKBASEDPARALLELISM_TASK_FIB_H

#include "control_state.h"
#include "loadBalancer.h"
#include "taskQueue.h"
#include "task.h"

class Task_fib : public Task {
    const unsigned index;
    Control_state *control;
    unsigned *result_ptr;

    Task_fib(unsigned n, Control_state *ctrl, unsigned *result_addr) : index(n), control(ctrl),
                                                                       result_ptr(result_addr) {}

public:

    static Task_fib *create(unsigned n, unsigned *result_addr, Control_state *parent = nullptr);

    void run();
};


#endif //TASKBASEDPARALLELISM_TASK_FIB_H
