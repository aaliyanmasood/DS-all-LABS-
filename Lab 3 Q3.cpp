#include <iostream>
#include <string>
using namespace std;

struct Passenger {
 string name;
  Passenger* next;
};

class ReservationSystem {
private:
Passenger* head;

public:
ReservationSystem() {
     head = nullptr;
}

 void reserveTicket(const string& name) {
   Passenger* newPassenger = new Passenger{name, nullptr};
        if (!head || name < head->name) {
            newPassenger->next = head;
            head = newPassenger;
            return;
        }

        Passenger* current = head;
        while (current->next && current->next->name < name) {
            current = current->next;
        }

        if (current->name == name || (current->next && current->next->name == name)) {
            delete newPassenger;
            return;
        }

        newPassenger->next = current->next;
        current->next = newPassenger;
    }

    void cancelReservation(const string& name) {
        if (!head) return;

        if (head->name == name) {
            Passenger* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Passenger* current = head;
        while (current->next && current->next->name != name) {
            current = current->next;
        }

        if (current->next && current->next->name == name) {
            Passenger* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    bool isReserved(const string& name) {
        Passenger* current = head;
        while (current) {
            if (current->name == name) return true;
            current = current->next;
        }
        return false;
    }

    void displayPassengers() {
        Passenger* current = head;
        while (current) {
            cout << current->name << endl;
            current = current->next;
        }
    }

    ~ReservationSystem() {
        while (head) {
            Passenger* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ReservationSystem system;
    int choice=0;
    string name;
     while (choice != 5){
        cout << "\n1. Reserve Ticket\n2. Cancel Reservation\n3. Check Reservation\n4. Display Passengers\n5. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
          case 1:
                cout << "Enter Name to reserve : ";
                getline(cin, name);
                system.reserveTicket(name);
                break;
         case 2:
                cout << "Enters name to cancel : ";
                getline(cin, name);
                system.cancelReservation(name);
                break;
        case 3:
                cout << "enter the Name to check : ";
                getline(cin, name);
                if (system.isReserved(name)) cout << "Ticket is Reserved.\n";
                else cout << "No reservation founded.\n";
                break;
        case 4:
                cout << "Passenger List :\n";
                system.displayPassengers();
                break;
        }
    };

    return 0;
}
