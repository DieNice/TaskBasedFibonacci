#ifndef TASKBASEDPARALLELISM_CONTROL_STATE_H
#define TASKBASEDPARALLELISM_CONTROL_STATE_H


class Control_state {
public:

    virtual ~Control_state() {}

    virtual void at_exit() = 0;
};


#endif //TASKBASEDPARALLELISM_CONTROL_STATE_H
