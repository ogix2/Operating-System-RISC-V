#include "../h/scheduler.hpp"

Queue<TCB*> Scheduler::readyThreadQueue;
TCB* Scheduler::running = nullptr;

TCB* Scheduler::get()
{
    return readyThreadQueue.pop_front();
}

void Scheduler::put(TCB* tcb)
{
    readyThreadQueue.push_back(tcb);
}
/*
void Scheduler::set_finished(){
    running->finished = true;
}*/
void Scheduler::set_finished(){}
void Scheduler::yield(){}
/*
void Scheduler::yield(){
    asm volatile ("addi sp, sp, -88");
    asm volatile ("sd x0, 0(sp)");
    asm volatile ("sd x1, 8(sp)");
    //asm volatile ("sd x2, 16(sp)");
    asm volatile ("sd x3, 24(sp)");
    asm volatile ("sd x4, 32(sp)");
    asm volatile ("sd x5, 40(sp)");
    asm volatile ("sd x6, 48(sp)");
    asm volatile ("sd x7, 56(sp)");
    asm volatile ("sd x8, 64(sp)");
    asm volatile ("sd x9, 72(sp)");
    asm volatile ("sd x10, 80(sp)");

    TCB* old_thread = Scheduler::running;
    TCB* new_thread = Scheduler::get();

    asm volatile ("addi %0, sp, 0" : "=r" (old_thread->sp));

    if (!old_thread->finished) Scheduler::put(old_thread);


    if(!new_thread->init) {
        new_thread->init = true;
        asm volatile ("addi ra, %0 ,0" : : "r" (new_thread->start_address));
        asm volatile ("addi sp, %0 ,0" : : "r" (new_thread->sp));
        return;
    }
    else {
        asm volatile ("addi sp, %0, 0" : : "r" (new_thread->sp));
        asm volatile ("ld x0, 0(sp)");
        asm volatile ("sd x1, 8(sp)");
        //asm volatile ("sd x2, 16(sp)");
        asm volatile ("sd x3, 24(sp)");
        asm volatile ("sd x4, 32(sp)");
        asm volatile ("sd x5, 40(sp)");
        asm volatile ("sd x6, 48(sp)");
        asm volatile ("sd x7, 56(sp)");
        asm volatile ("sd x8, 64(sp)");
        asm volatile ("sd x9, 72(sp)");
        asm volatile ("sd x10, 80(sp)");
        asm volatile ("addi sp, sp, 88");

        return;
    }
}
*/