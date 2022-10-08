#ifndef TASK_RINGBUFFERLIST_H
#define TASK_RINGBUFFERLIST_H

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node<T> *next = NULL;
};

template<typename T>
class RingBufferList {
private:
    Node<T> *head;

public:
    RingBufferList();

    Node<T> *create(T);

    void InsertBegin(T);

    void InsertTail(T);

    void InsertAtPosition(T, int);

    void DeleteAtPosition(int position);

    void Display();

    ~RingBufferList();
};

#endif // TASK_RINGBUFFERLIST_H
