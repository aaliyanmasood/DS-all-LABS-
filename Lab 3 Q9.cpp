#include <iostream>
using namespace std;

struct Node {
int data;
Node* next;
};

class LinkedList {
private:
Node* head;

public:
LinkedList() {
    head = nullptr;
}

void insert(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

void process() {
    if (!head || !head->next)
        return;

    Node* original = head;
    Node* extracted = head->next;
    Node* extractedHead = extracted;

    while (original && original->next && extracted && extracted->next) {
        original->next = extracted->next;
        original = original->next;
        extracted->next = original->next;
        extracted = extracted->next;
    }

    Node* prev = nullptr;
    Node* curr = extractedHead;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* tail = head;
    while (tail->next)
        tail = tail->next;
    tail->next = prev;
}

void display() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
};

int main() {
LinkedList list;
int n, value;

cout << "Enter number of elements: ";
cin >> n;

for (int i = 0; i < n; ++i) {
    cin >> value;
    list.insert(value);
}

cout << "Original List: ";
list.display();

list.process();

cout << "Modified List: ";
list.display();

return 0;
}
