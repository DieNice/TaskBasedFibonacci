#include "control_state_fib_async.h"


Control_state_fib_async * Control_state_fib_async::create(unsigned int *result_addr, Control_state *parent)  {
    return new Control_state_fib_async{result_addr, parent};
}

unsigned int *Control_state_fib_async::result1_ptr() {
    return &r1;
}

unsigned int *Control_state_fib_async::result2_ptr() {
    return &r2;
}

void Control_state_fib_async::at_exit() {
    if (--ctr == 0) {
        *result_ptr = r1 + r2;
        parent_state->at_exit();
        delete this;

    }
}