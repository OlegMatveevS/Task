#ifndef TASK_RINGBUFFER_H
#define TASK_RINGBUFFER_H
#include <iostream>

class RingBuffer {
private:
    int front = -1;
    int rear = -1;
    int size;
    int *buffer;
public:
    RingBuffer(int size);

    bool full() const;

    bool empty() const;

    bool checkPointer() const;

    void resize();

    void push(int);

    int pop();

    void Display();

    ~RingBuffer();

};


#endif //TASK_RINGBUFFER_H
