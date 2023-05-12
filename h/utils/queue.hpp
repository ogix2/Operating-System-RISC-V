#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue{
public:
    Queue() : front(nullptr), back(nullptr) {}
    ~Queue();

    void push_back(T elem);

    T pop_front();

private:
    struct Node
    {
        T data;
        Node *next = nullptr;
        Node *previous = nullptr;

        Node(T data) : data(data) {}
    };


    Node* front;
    Node* back;
};

#include "queue_impl.hpp"

#endif