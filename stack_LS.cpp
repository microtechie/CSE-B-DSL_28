#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Top pointer
Node* top = NULL;

// Push operation
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed into stack\n";
}

// Pop operation
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << temp->data << " popped from stack\n";
    top = top->next;
    delete temp;
}

// Peek operation
void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element: " << top->data << endl;
    }
}

// Display stack
void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();
    display();

    return 0;
}
