#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


Node* head = NULL;


void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void deleteNode(int value) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
}


void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


int main() {

    insertAtBeginning(10);
    insertAtBeginning(5);
    insertAtEnd(20);
    insertAtEnd(30);

    cout << "Linked List: ";
    display();

    deleteNode(20);

    cout << "After Deletion: ";
    display();

    return 0;
}
