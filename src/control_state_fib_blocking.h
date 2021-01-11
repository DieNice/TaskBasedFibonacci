#ifndef TASKBASEDPARALLELISM_CONTROL_STATE_FIB_BLOCKING_H
#define TASKBASEDPARALLELISM_CONTROL_STATE_FIB_BLOCKING_H

#include <mutex>
#include <condition_variable>
#include "control_state.h"

class Control_state_fib_blocking : public Control_state{
    bool ready = false;
    std::condition_variable cv;
    std::mutex mtx;
    unsigned *result_ptr;

public:

    Control_state_fib_blocking(unsigned *result_addr) : result_ptr(result_addr) {}

    void at_exit();

    void wait();
};


#endif //TASKBASEDPARALLELISM_CONTROL_STATE_FIB_BLOCKING_H
