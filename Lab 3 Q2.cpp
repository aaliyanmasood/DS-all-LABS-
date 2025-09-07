#include <iostream>
using namespace std;

class Node {
public:
int data;
Node* next;
Node(int value) {
    data = value;
    next = nullptr;
}
};

class LinkedList {
public:
Node* head;
Node* tail;
LinkedList() {
    head = nullptr;
    tail = nullptr;
}
};

int main() {
LinkedList obj;
int count = 1;
int temp;
Node* ptr;
for (int i = 0; i < 7; i++) {
    if (i == 0) {
        ptr = new Node(8 - i);
        obj.head = ptr;
    } else {
        ptr->next = new Node(8 - i);
        ptr = ptr->next;
    }
    if (i == 6) {
        obj.tail = ptr;
    }
}
ptr = obj.head;
cout << "Original List:\n";
while (ptr != nullptr) {
    cout << ptr->data << endl;
    ptr = ptr->next;
}

cout << "Enter Number of Elements to be moved to end (less than 7): ";
cin >> temp;

if (temp > 0 && temp < 7) {
    ptr = obj.head;
    obj.tail->next = obj.head;
    for (int i = 1; i < temp; i++) {
        ptr = ptr->next;
    }

    obj.head = ptr->next; 
    ptr->next = nullptr;

    obj.tail = ptr;
}
ptr = obj.head;
cout << "Modified List:\n";
while (ptr != nullptr) {
    cout << ptr->data << endl;
    ptr = ptr->next;
}

return 0;
}
