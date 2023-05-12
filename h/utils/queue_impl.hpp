#ifndef QUEUE_IMPL_HPP
#define QUEUE_IMPL_HPP

#include "queue.hpp"

template<typename T>
Queue<T>::~Queue() {
    while(front != nullptr){
        Node* tmp = front;
        front = front->next;

        delete tmp;
    }
}

template<typename T>
T Queue<T>::pop_front() {
    // if Queue is empty -> front = nullptr, back = nullptr, exception occurs
    // one element Queue, has to change back also
    if (front == back){
        T tmp_data = front->data;
        delete front;
        front = nullptr;
        back = nullptr;
        return tmp_data;
    }
    else {
        Node *tmp_node = front;
        T tmp_data = front->data;
        front = front->next;
        front->previous = nullptr;

        delete tmp_node;
        return tmp_data;
    }
}

template<typename T>
void Queue<T>::push_back(T elem) {

    Node* tmp = new Node(elem);

    if(back == nullptr){
        back = tmp;
        front = tmp;
    }
    else {
        back->next = tmp;
        tmp->previous = back;
        back = tmp;
    }
}


#endif