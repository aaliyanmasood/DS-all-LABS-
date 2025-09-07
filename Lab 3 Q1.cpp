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
int arr[5] = {3, 1, 2, 5, 8};
LinkedList obj;
Node* ptr;

for (int i = 0; i < 5; i++) {
    cout << arr[i] << endl;
    if (i == 0) {
        obj.head = new Node(arr[0]);
        ptr = obj.head;
    } else {
        ptr->next = new Node(arr[i]);
        if (i == 4) {
            obj.tail = ptr->next;
        }
        ptr = ptr->next;
    }
}

ptr = obj.head;
for (int i = 0; i < 5; i++) {
    cout << ptr->data << endl;
    ptr = ptr->next;
}

cout << "\n\n";

ptr = new Node(4);
ptr->next = obj.head;
obj.head = ptr;

ptr = obj.head;
while (ptr->next != nullptr) {
    if (ptr->data == 3) {
        ptr->data = 4;
    }
    cout << ptr->data << endl;
    ptr = ptr->next;
}
cout << ptr->data << endl;

return 0;
}
