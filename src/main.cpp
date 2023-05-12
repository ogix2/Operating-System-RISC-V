#include "../h/scheduler.hpp"
#include "../h/workers.hpp"
#include "../h/print.hpp"


void main(){
    TCB* threads[3];

    threads[0] = TCB::create_main_thread();
    Scheduler::running = threads[0];

    threads[1] = TCB::create_thread(workerBodyA);
    Scheduler::put(threads[1]);
    threads[2] = TCB::create_thread(workerBodyB);
    Scheduler::put(threads[2]);

    while (!(threads[1]->get_finished() &&
            threads[2]->get_finished()))
    {
        printString("MAIN \n");

        Scheduler::yield();
    }

    for (TCB* thread : threads)
    {
        delete thread;
    }
}