#include "RingBufferList.h"


RingBufferList::RingBufferList() {
    head = NULL;
}

Node *RingBufferList::create(int localData) {
    Node *node = new Node;
    node->data = localData;
    node->next = NULL;
    return node;
}

void RingBufferList::InsertBegin(int dataItem) {
    Node *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        head = node;
    }
}

void RingBufferList::InsertTail(int dataItem) {
    Node *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
    }
    node->next = head;
}

void RingBufferList::InsertAtPosition(int dataItem, int position) {
    Node *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        if (position == 1) {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = node;
            node->next = head;
            head = node;
        } else {
            Node *temp = head;
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

void RingBufferList::DeleteAtPosition(int position) {
    if (head == NULL) {
        std::cout << "Can't delete\n";
    } else {
        if (position == 1) {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
        } else {
            Node *temp = head;
            Node *prev = NULL;
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

void RingBufferList::Display() {
    Node *temp = head;

    do {
        std::cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);
}

RingBufferList::~RingBufferList() {
    Node *p = head, *q;
    while ((p != NULL) && (p->next != NULL)) {
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        delete q;
        p = p->next;
    }
}

int main() {
    RingBufferList ListOne;

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

