#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

class CircularLinkedList {
private:
Node* tail;

public:
CircularLinkedList() {
    tail = nullptr;
}

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
}

void insertAtPosition(int value, int pos) {
    if (pos <= 1 || !tail) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node{value, nullptr};
    Node* current = tail->next;
    int count = 1;

    while (count < pos - 1 && current != tail) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    current->next = newNode;

    if (current == tail)
        tail = newNode;
}

void deleteNode(int value) {
    if (!tail) return;

    Node* current = tail->next;
    Node* prev = tail;

    do {
        if (current->data == value) {
            if (current == tail && current->next == tail) {
                delete current;
                tail = nullptr;
                return;
            }

            if (current == tail) {
                prev->next = current->next;
                tail = prev;
            } else {
                prev->next = current->next;
            }

            if (current == tail->next)
                tail->next = current->next;

            delete current;
            return;
        }

        prev = current;
        current = current->next;

    } while (current != tail->next);
}

void display() {
    if (!tail) {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

~CircularLinkedList() {
    if (!tail) return;
    Node* current = tail->next;
    tail->next = nullptr;

    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
};

int main() {
CircularLinkedList clist;
int choice, value, position;

do {
    cout << "\n1. Insert at End\n2. Insert at Beginning\n3. Insert at Position\n4. Delete Node\n5. Display\n6. Exit\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            clist.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            clist.insertAtBeginning(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> position;
            clist.insertAtPosition(value, position);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            clist.deleteNode(value);
            break;
        case 5:
            clist.display();
            break;
    }

} while (choice != 6);

return 0;
}
