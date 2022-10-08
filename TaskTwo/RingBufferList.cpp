#include "RingBufferList.h"

template<typename T>
RingBufferList<T>::RingBufferList() {
    head = NULL;
}

template<typename T>
Node<T> *RingBufferList<T>::create(T localData) {
    Node<T> *node = new Node<T>;
    node->data = localData;
    node->next = NULL;
    return node;
}

template<typename T>
void RingBufferList<T>::InsertBegin(T dataItem) {
    Node<T> *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        Node<T> *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        head = node;
    }
}

template<typename T>
void RingBufferList<T>::InsertTail(T dataItem) {
    Node<T> *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        Node<T> *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
    }
    node->next = head;
}

template<typename T>
void RingBufferList<T>::InsertAtPosition(T dataItem, int position) {
    Node<T> *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        if (position == 1) {
            Node<T> *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = node;
            node->next = head;
            head = node;
        } else {
            Node<T> *temp = head;
            for (int i = 1; i < position - 1; i++) {
                if (temp->next == head) {
                    break;
                }
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }
}

template<typename T>
void RingBufferList<T>::DeleteAtPosition(int position) {
    if (head == NULL) {
        std::cout << "Can't delete\n";
    } else {
        if (position == 1) {
            Node<T> *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
        } else {
            Node<T> *temp = head;
            Node<T> *prev = NULL;
            for (int i = 1; i < position - 1; i++) {
                if (temp->next == head) {
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
}

template<typename T>
void RingBufferList<T>::Display() {
    Node<T> *temp = head;

    do {
        std::cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);
}

template<typename T>
RingBufferList<T>::~RingBufferList() {
    Node<T> *p = head, *q;
    while ((p != NULL) && (p->next != NULL)) {
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        delete q;
        p = p->next;
    }
}

int main() {
    RingBufferList<int> ListOne;

    for (int i = 0; i <= 10; i++) {
        ListOne.InsertBegin(i);
    }
    for (int i = 10; i <= 15; i++) {
        ListOne.InsertTail(i);
    }
    ListOne.InsertAtPosition(20, 1);
    ListOne.DeleteAtPosition(3);
    ListOne.Display();
    return 0;
}

