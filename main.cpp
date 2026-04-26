#include <iostream>
using namespace std;

#define MAX 5

string queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is full
bool isFull() {
    return (rear == MAX - 1);
}

// Check if queue is empty
bool isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue (Add Employee)
void enqueue() {
    if (isFull()) {
        cout << "Queue is FULL! Cannot add more employees.\n";
        return;
    }

    string name;
    cout << "Enter employee name: ";
    cin >> name;

    if (front == -1) front = 0;

    rear++;
    queue[rear] = name;

    cout << "Employee added successfully.\n";
}

// Dequeue (Serve Employee)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! No employee to serve.\n";
        return;
    }

    cout << "Serving employee: " << queue[front] << endl;
    front++;
}

// Display Queue
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY.\n";
        return;
    }

    cout << "\nEmployees in queue:\n";
    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". " << queue[i] << endl;
    }
}

// 🔍 Search Employee
void searchEmployee() {
    if (isEmpty()) {
        cout << "Queue is EMPTY.\n";
        return;
    }

    string name;
    cout << "Enter employee name to search: ";
    cin >> name;

    bool found = false;

    for (int i = front; i <= rear; i++) {
        if (queue[i] == name) {
            cout << "Employee found at position: " << i - front + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found in queue.\n";
    }
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== AMU Employee Service System =====\n";
        cout << "1. Add Employee (Enqueue)\n";
        cout << "2. Serve Employee (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Search Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
