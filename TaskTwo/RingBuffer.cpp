#include <iostream>

class RingBuffer {

private:
    int front = -1;
    int rear = -1;
    int size = 4;
    int *elements = &size;
public:
    bool full();

    bool empty();

    void resize();

    void push(int);

    int pop();

    void Display();

};


bool RingBuffer::full() {
    return (front == (rear + 1) % size);
}

bool RingBuffer::empty() {
    return (front == rear + 1);
}

void RingBuffer::resize() {
    int *foo = new int[size * 2];
    for (int i = 0; i < size; i++) {
        foo[i] = elements[i];
    }
    delete[] elements;
    elements = foo;
    size *= 2;
}

void RingBuffer::push(int element) {
    if (full()) {
        resize();
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    elements[rear] = element;

}

int RingBuffer::pop() {
    int element;
    if (empty()) {
        std::cout << "circleBuffer is empty" << std::endl;
        return (-1);
    } else {
        element = elements[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return (element);
    }
}

void RingBuffer::Display() {
    int i;
    {
        for (i = 0; i < size; i++) {
            std::cout << elements[i];
        }
    }
}


int main() {
    RingBuffer ringBuffer;
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
};



