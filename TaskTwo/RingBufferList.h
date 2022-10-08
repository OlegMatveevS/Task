#ifndef TASK_RINGBUFFERLIST_H
#define TASK_RINGBUFFERLIST_H
#include <iostream>

struct Node {
    int data;
    Node *next = NULL;
};

class RingBufferList {
private:
    Node *head;
public:
    RingBufferList();

    Node *create(int);

    void InsertBegin(int);

    void InsertTail(int);

    void InsertAtPosition(int, int);

    void Display();

    ~RingBufferList();

};

#endif //TASK_RINGBUFFERLIST_H
