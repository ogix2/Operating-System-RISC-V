#ifndef TCB_HPP
#define TCB_HPP

#include "../lib/hw.h"

typedef void (*Body)();

class TCB {
public:
    ~TCB();

    static TCB* create_thread(Body body);

    static TCB* create_main_thread();

    bool get_finished() {return finished;}

    void set_finished(bool finish) {finished = finish;}

private:
    TCB(Body body) :
            start_address((uint64) body),
            stack(new uint64[DEFAULT_STACK_SIZE]),
            sp((uint64) &stack[DEFAULT_STACK_SIZE]),
            finished(false),
            init(false)
    {}
    TCB() :
            start_address(0),
            stack(0),
            sp(0),
            finished(false),
            init(true)
    {}

    uint64 start_address;
    uint64 *stack;
    uint64 sp;
    bool finished;
    bool init;

    friend class Scheduler;
};


#endif