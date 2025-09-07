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

void rearrangeEvenOdd() {
    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* current = head;

    while (current) {
        if (current->data % 2 == 0) {
            if (!evenHead) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (!oddHead) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    if (evenTail)
        evenTail->next = oddHead;
    if (oddTail)
        oddTail->next = nullptr;

    head = evenHead ? evenHead : oddHead;
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
    cout << "Original list: ";
    list.display();
    list.rearrangeEvenOdd();
    cout << "Modified list: ";
    list.display();
    return 0;
}