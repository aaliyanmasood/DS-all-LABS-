#include <iostream>
#include <string>
using namespace std;

struct Node {
string data;
Node* prev;
Node* next;
};

class DoublyLinkedList {
public:
Node* head;
Node* tail;

DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void insert(const string& value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void display() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void concatenate(DoublyLinkedList& other) {
    if (!other.head) return;
    if (!head) {
        head = other.head;
        tail = other.tail;
        return;
    }

    tail->next = other.head;
    other.head->prev = tail;
    tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;
}

~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
};

int main() {
DoublyLinkedList L, M;
int n;
string value;

cout << "Enter number of elements in List L: ";
cin >> n;
cin.ignore();
for (int i = 0; i < n; ++i) {
    getline(cin, value);
    L.insert(value);
}

cout << "Enter number of elements in List M: ";
cin >> n;
cin.ignore();
for (int i = 0; i < n; ++i) {
    getline(cin, value);
    M.insert(value);
}

cout << "List L: ";
L.display();

cout << "List M: ";
M.display();

L.concatenate(M);

cout << "Concatenated List: ";
L.display();

return 0;
}
