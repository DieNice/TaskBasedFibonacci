#ifndef TASKBASEDPARALLELISM_CONTROL_STATE_FIB_ASYNC_H
#define TASKBASEDPARALLELISM_CONTROL_STATE_FIB_ASYNC_H

#include "atomic"
#include "control_state.h"

class Control_state_fib_async : public Control_state {
    unsigned *result_ptr;
    unsigned r1, r2;
    Control_state *parent_state;
    std::atomic<unsigned> ctr;

    Control_state_fib_async(unsigned *result_addr, Control_state *parent = nullptr) : result_ptr(result_addr),
                                                                                      parent_state(parent), ctr(2) {}

public:

    static Control_state_fib_async *create(unsigned *result_addr, Control_state *parent = nullptr);

    unsigned *result1_ptr();

    unsigned *result2_ptr();

    void at_exit();
};


#endif //TASKBASEDPARALLELISM_CONTROL_STATE_FIB_ASYNC_H
