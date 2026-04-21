#include <iostream>
using namespace std;

struct Node {
int data;
Node *prev; 
Node *next; 
Node(int val) {
  data = val;
  prev = nullptr;
    next = nullptr;
}
};

Node* insert(Node* root, int val) {
if (!root) return new Node(val);
if (val < root->data)
root->prev = insert(root->prev, val);
else if (val > root->data)
root->next = insert(root->next, val);
return root;
}

bool search(Node* root, int key) {
if (!root) return false;
if (root->data == key) return true;
return (key < root->data) ? search(root->prev, key) : search(root->next, key);
}

void inorder(Node* root) {
if (root) {
inorder(root->prev);
cout << root->data << " ";
inorder(root->next);
}
}

void preorder(Node* root) {
if (root) {
cout << root->data << " ";
preorder(root->prev);
preorder(root->next);
}
}

void postorder(Node* root) {
if (root) {
postorder(root->prev);
postorder(root->next);
cout << root->data << " ";
}
}

int main() {
Node* root = nullptr;
int choice, value, size;

while (true) {
cout << "\n\n--- Binary Search Tree Menu ---";
cout << "\n1. Create Tree";
cout << "\n2. Search for a Value";
cout << "\n3. Inorder Traversal";
cout << "\n4. Preorder Traversal";
cout << "\n5. Postorder Traversal";
cout << "\n6. Exit";
cout << "\n\nEnter choice: ";
cin >> choice;

switch (choice) {
case 1:
cout << "Number of elements you want to insert: ";
cin >> size;
for (int i = 0; i < size; i++) {
cout << "Enter element " << i + 1 << ": ";
cin >> value;
root = insert(root, value);
}
cout << "Successfully added " << size << " elements.";
break;

case 2:
if (!root) {
cout << "The tree is empty!";
} else {
cout << "Enter value to search: ";
cin >> value;
if (search(root, value))
cout << value << " is found in the tree.";
else
cout << value << " was not found.";
}
break;

case 3:
cout << "Inorder Traversal: ";
inorder(root);
break;

case 4:
cout << "Preorder Traversal: ";
preorder(root);
break;

case 5:
cout << "Postorder Traversal: ";
postorder(root);
break;

case 6:
cout << "Exiting... \n";
return 0;

default:
cout << "Invalid choice! Please select 1-6.";
}
}
return 0;
}
