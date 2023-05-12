#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "utils/queue.hpp"
#include "tcb.hpp"

class TCB;

class Scheduler{
public:
    static TCB* get();

    static void put(TCB* tcb);

    static void yield();

    static void set_finished();

    static TCB* running;

private:
    static Queue<TCB*> readyThreadQueue;
};


#endif