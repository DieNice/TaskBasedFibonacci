#include <iostream>
#include "src/loadBalancer.h"
#include "src/control_state.h"
#include "src/control_state_fib_async.h"
#include "src/control_state_fib_blocking.h"
#include "src/task_fib.h"

unsigned parallel_fibonacci(unsigned n) {

    unsigned result;

    Control_state_fib_blocking ctrl{&result};

    auto task = Task_fib::create(n, &result, &ctrl);

    lb.add_task(task);

    ctrl.wait();

    return result;

}

int main() {
    std::cout << parallel_fibonacci(6) << '\n';  // 0 1 1 2 3 5 8
    return 0;
}
