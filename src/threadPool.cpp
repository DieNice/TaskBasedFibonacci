#include "threadPool.h"

ThreadPool::ThreadPool(TaskQueue *q, unsigned thread_count) {
    queue = q;
    for (unsigned i = 0; i < thread_count; ++i)
        threads.emplace_back(thread_proc, q);

}

void ThreadPool::terminate() {
    for (unsigned i = 0; i < threads.size(); ++i) {
        queue->push_task(nullptr);
    }
    for (auto &thread:threads)
        thread.join();D

}

void ThreadPool::thread_proc(TaskQueue *q) {
    while (true) {
        Task *tsk = q->pop_task();
        if (tsk == nullptr)
            break;
        tsk->run();
    }
}
