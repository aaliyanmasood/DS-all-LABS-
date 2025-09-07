#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
T data;
Node* next;
};

template <typename T>
class LinkedList {
private:
Node<T>* head;

public:
LinkedList() {
    head = nullptr;
}

void insert(T value) {
    Node<T>* newNode = new Node<T>{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

bool isPalindrome() {
    int size = 0;
    Node<T>* current = head;
    while (current) {
        size++;
        current = current->next;
    }

    T* arr = new T[size];
    current = head;
    for (int i = 0; i < size; ++i) {
        arr[i] = current->data;
        current = current->next;
    }

    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        if (arr[i] != arr[j]) {
            delete[] arr;
            return false;
        }
    }

    delete[] arr;
    return true;
}

void display() {
    Node<T>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

~LinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
};

int main() {
LinkedList<string> list;
int n;
string value;

cout << "Enter Number of Elements : ";
cin >> n;
cin.ignore();

for (int i = 0; i < n; ++i) {
    getline(cin, value);
    list.insert(value);
}

cout << "Linked List: ";
list.display();

if (list.isPalindrome())
    cout << "The linked list is a paliendrome." << endl;
else
    cout << "The linked list is not a paliendrome." << endl;
return 0;
}
