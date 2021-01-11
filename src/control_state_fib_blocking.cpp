#include "control_state_fib_blocking.h"

void Control_state_fib_blocking::at_exit() {
    std::unique_lock lock{mtx};
    ready = true;
    cv.notify_all();
}

void Control_state_fib_blocking::wait() {
    std::unique_lock lock{mtx};
    while (!ready)
        cv.wait(lock);
}