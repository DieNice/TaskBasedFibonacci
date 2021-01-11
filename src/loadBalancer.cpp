#include "loadBalancer.h"

LoadBalancer::~LoadBalancer() {
    pool.terminate();
    q.clr();
    q.wait_until_empty();
}

void LoadBalancer::add_task(Task *tsk) {
    q.push_task(tsk);
}