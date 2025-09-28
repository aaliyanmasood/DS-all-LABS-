#include<iostream>
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
int count(Node *ptr){
    if(ptr->next!=nullptr){
        return 1 + count(ptr->next);
    }
    else return 1;
};
int main() {
int arr[5] = {3, 1, 2, 5, 8};
LinkedList obj;
Node* ptr;

for (int i = 0; i < 5; i++) {
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
cout<<"Value= "<<count(obj.head);
}