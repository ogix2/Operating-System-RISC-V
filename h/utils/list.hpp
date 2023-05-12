#ifndef LIST_HPP
#define LIST_HPP

template<typename T>
class List{
public:
    List() : front(nullptr), back(nullptr) {}
    ~List();

    void push_back(T elem);

    void push_front(T elem);

    T pop_back();

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

#include "list_impl.hpp"
#endif