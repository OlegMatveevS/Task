#include <list>


struct Node {
    int data;
    Node *next = NULL;
};

class CircularRingList {
private:
    Node *head;
public:
    CircularRingList() { head = NULL; }

    Node *create(int);

    void InsertBegin(int);

    void InsertTail(int);

    void InsertAtPosition(int, int);

    void Display();

};

Node *CircularRingList::create(int localData) {
    try {
        Node *node = new Node;
        node->data = localData;
        node->next = NULL;
        return node;
    }
    catch (std::bad_alloc xa) {
        std::cout << "Can't Allocate Memory\n";
        return NULL;
    }
}

void CircularRingList::InsertBegin(int dataItem) {
    Node *node = create(dataItem);
    if (head == NULL) {
        head = node;
        head->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = node;
        node->next = head;
        head = node;
    }
}

void CircularRingList::InsertTail(int dataItem) {
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

void CircularRingList::InsertAtPosition(int dataItem, int position) {
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

void CircularRingList::Display() {
    std::cout << std::endl;
    Node *temp = head;

    do {
        std::cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != head);
}

int main() {
    CircularRingList ListOne;

    for (int i = 0; i <= 10; i++) {
        ListOne.InsertBegin(i);

    }
    for (int i = 10; i <= 15; i++) {
        ListOne.InsertTail(i);
    }
    ListOne.InsertAtPosition(100, 1);
    ListOne.Display();
    return 0;
}

