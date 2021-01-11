#include "task_fib.h"
#include "control_state_fib_async.h"

Task_fib *Task_fib::create(unsigned n, unsigned *result_addr, Control_state *parent) {
    return new Task_fib(n, parent, result_addr);
}

void Task_fib::run() {
    if (index < 2) {
        *result_ptr = index;
        control->at_exit();
    } else {

        auto ctrl = Control_state_fib_async::create(result_ptr, control);
        auto task1 = Task_fib::create(index - 1, ctrl->result1_ptr(), ctrl);
        auto task2 = Task_fib::create(index - 2, ctrl->result2_ptr(), ctrl);

        lb.add_task(task1);
        lb.add_task(task2);

    }
}