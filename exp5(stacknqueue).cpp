#include <iostream>
using namespace std;

#define SIZE 5

// ---------- STACK ----------
int stackArr[SIZE];
int top = -1;

void push() {
    int value;
    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
    } else {
        cout << "Enter value: ";
        cin >> value;
        top++;
        stackArr[top] = value;
        cout << "Value pushed\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Popped value: " << stackArr[top] << endl;
        top--;
    }
}

void displayStack() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

// ---------- QUEUE ----------
int queueArr[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int value;
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
    } else {
        cout << "Enter value: ";
        cin >> value;
        if (front == -1)
            front = 0;
        rear++;
        queueArr[rear] = value;
        cout << "Value inserted\n";
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
    } else {
        cout << "Deleted value: " << queueArr[front] << endl;
        front++;
    }
}

void displayQueue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements:\n";
        for (int i = front; i <= rear; i++) {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}

// ---------- MAIN ----------
int main() {
    int choice;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Push (Stack)\n";
        cout << "2. Pop (Stack)\n";
        cout << "3. Display Stack\n";
        cout << "4. Enqueue (Queue)\n";
        cout << "5. Dequeue (Queue)\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: cout << "Program Ended\n"; break;
            default: cout << "Invalid Choice\n";
        }

    } while (choice != 7);

    return 0;
}
