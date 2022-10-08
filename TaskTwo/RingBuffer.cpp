#include "RingBuffer.h"

RingBuffer::RingBuffer(int size) {
    size = size;
    this->buffer = new int[size];
    this->size = size;
};

bool RingBuffer::full() const {
    return (front == (rear + 1) % size);
}

bool RingBuffer::empty() const {
    return (front == rear + 1);
}

bool RingBuffer::checkPointer() const {
    return (front == rear);
}

void RingBuffer::resize() {
    int *foo = new int[size * 2];
    for (int i = 0; i < size; i++) {
        foo[i] = buffer[i];
    }
    delete[] buffer;
    buffer = foo;
    size *= 2;
}

void RingBuffer::push(int element) {
    if (full()) {
        resize();
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    buffer[rear] = element;
}

int RingBuffer::pop() {
    int element;
    if (empty()) {
        std::cout << "circleBuffer is empty" << std::endl;
        return (-1);
    } else {
        element = buffer[front];
        if (checkPointer()) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return (element);
    }
}

void RingBuffer::Display() {
    {
        for (int i = 0; i < size; i++) {
            std::cout << buffer[i];
        }
    }
}

RingBuffer::~RingBuffer()
{
    delete[] buffer;
}





int main() {
    RingBuffer ringBuffer(6);
    ringBuffer.push(2);
    ringBuffer.push(3);
    ringBuffer.push(4);
    ringBuffer.push(1);
    ringBuffer.push(1);
    ringBuffer.push(1);
    ringBuffer.push(1);
    ringBuffer.push(1);
    ringBuffer.push(2);
    ringBuffer.Display();
    return 0;
}