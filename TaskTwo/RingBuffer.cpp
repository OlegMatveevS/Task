#include "RingBuffer.h"

template<typename T>
RingBuffer<T>::RingBuffer(int size) {
    size = size;
    this->buffer = new int[size];
    this->size = size;
};

template<typename T>
bool RingBuffer<T>::full() const {
    return (front == (rear + 1) % size);
}

template<typename T>
bool RingBuffer<T>::empty() const {
    return (front == rear + 1);
}

template<typename T>
bool RingBuffer<T>::checkPointer() const {
    return (front == rear);
}

template<typename T>
void RingBuffer<T>::resize() {
    int *foo = new int[size * 2];
    for (int i = 0; i < size; i++) {
        foo[i] = buffer[i];
    }
    delete[] buffer;
    buffer = foo;
    size *= 2;
}

template<typename T>
void RingBuffer<T>::push(int element) {
    if (full()) {
        resize();
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    buffer[rear] = element;
}

template<typename T>
int RingBuffer<T>::pop() {
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

template<typename T>
void RingBuffer<T>::Display() {
    {
        for (int i = 0; i < size; i++) {
            std::cout << buffer[i];
        }
    }
}

template<typename T>
RingBuffer<T>::~RingBuffer() {
    delete[] buffer;
}

int main() {
    RingBuffer<int> ringBuffer(6);
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