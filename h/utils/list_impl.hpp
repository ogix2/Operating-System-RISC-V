#ifndef LIST_IMPL_HPP
#define LIST_IMPL_HPP

#include "list.hpp"

template<typename T>
List<T>::~List() {
    while(front != nullptr){
        Node* tmp = front;
        front = front->next;

        delete tmp;
    }
}

template<typename T>
T List<T>::pop_front() {
    // if list is empty -> front = nullptr, back = nullptr, exception occurs
    // one element list, has to change back also
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
T List<T>::pop_back() {
    // if list is empty -> front = nullptr, back = nullptr, exception occurs
    // one element list, has to change front also
    if (front == back){
        T tmp_data = back->data;
        delete back;
        front = nullptr;
        back = nullptr;
        return tmp_data;
    }
    else {
        Node *tmp_node = back;
        T tmp_data = back->data;
        back = back->previous;
        back->next = nullptr;

        delete tmp_node;
        return tmp_data;
    }
}

template<typename T>
void List<T>::push_front(T elem) {

    Node* tmp = new Node(elem);

    if(front == nullptr){
        front = tmp;
        back = tmp;
    }
    else {
        front->previous = tmp;
        tmp->next = front;
        front = tmp;
    }

}

template<typename T>
void List<T>::push_back(T elem) {

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