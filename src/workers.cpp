#include "../h/scheduler.hpp"
#include "../h/print.hpp"

void workerBodyA(){

    printString("A1 \n");

    Scheduler::yield();

    printString("A2 \n");

    Scheduler::set_finished();
    Scheduler::yield();
}

void workerBodyB(){


    printString("B1 \n");

    Scheduler::yield();

    printString("B2 \n");

    Scheduler::set_finished();
    Scheduler::yield();
}