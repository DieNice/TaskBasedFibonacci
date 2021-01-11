#ifndef TASKBASEDPARALLELISM_TASK_H
#define TASKBASEDPARALLELISM_TASK_H


class Task {
public:
    virtual ~Task(){};

    virtual void run() = 0;
};


#endif //TASKBASEDPARALLELISM_TASK_H
