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
void count(Node *ptr, int input){
    if(ptr->data!=input&&ptr->next!=nullptr){
        return count(ptr->next, input);
    }
    else if(ptr->next==nullptr){
        cout<<"Value Not Found ";
    }
    else {cout<<"Input Value Found ";}
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
int temp;
cout<<"Enter value= ";
cin>>temp;
cout<<"Status: ";
count(obj.head, temp);
}