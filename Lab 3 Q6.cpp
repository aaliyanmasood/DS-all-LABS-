#include <iostream>
#include <string>
using namespace std;

struct Node {
string data;
Node* next;
};

class LinkedList {
private:
Node* head;

public:
LinkedList() {
    head = nullptr;
}

void insert(const string& value) {
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

void deleteValue(const string& value) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Value deleted." << endl;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data != value)
        current = current->next;

    if (current->next && current->next->data == value) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Value deleted." << endl;
    } else {
        cout << "Value not found in the list." << endl;
    }
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
int n;
string value;

cout << "Enter number of elements: ";
cin >> n;
cin.ignore();

for (int i = 0; i < n; ++i) {
    getline(cin, value);
    list.insert(value);
}

cout << "Original list: ";
list.display();

cout << "Enter value To delete : ";
getline(cin, value);

list.deleteValue(value);

cout << "List Updated : ";
list.display();

return 0;
}
