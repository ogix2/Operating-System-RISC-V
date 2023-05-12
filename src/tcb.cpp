#include "../h/tcb.hpp"

TCB::~TCB(){
    delete[] stack;
}

TCB* TCB::create_thread(Body body){
    return new TCB(body);
}

TCB* TCB::create_main_thread(){
    return new TCB();
}
