#include "taskQueue.h"

void TaskQueue::push_task(Task *tsk) {
    std::scoped_lock{mtx};
    q.push(tsk);
    cvNotEmpty.notify_all();
}

Task *TaskQueue::pop_task() {
    std::unique_lock lock(mtx);
    while (q.empty())
        cvNotEmpty.wait(lock);
    Task *result = q.front();
    q.pop();
    return result;
}

void TaskQueue::wait_until_empty() {
    std::unique_lock lock(mtx);
    while (!q.empty()) {
        cvEmpty.wait(lock);
    }
}

void TaskQueue::clr() {
    std::lock_guard lockGuard(mtx);
    while (!q.empty()) {
        q.pop();
    }
}