#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Front and Rear pointers
Node* front = NULL;
Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued\n";
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << temp->data << " dequeued\n";
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

// Peek (Front element)
void peek() {
    if (front == NULL) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

// Display queue
void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    peek();

    dequeue();
    display();

    return 0;
}
