#include<iostream>
using namespace std;
struct Node{
int data;
Node* left;
Node* right;
Node (int value) {
data=value;
left=nullptr;
right=nullptr;
}
};
Node* insert(Node* root, int value) {
if (root == nullptr) {
return new Node(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else {
root->right = insert(root->right, value);
}
return root;
}
void printTree(Node* root) {
if(root==nullptr)
return;
printTree(root->left);
cout<< root->data << " ";
printTree(root->right);
}
int main() {
Node* root = nullptr;
int size, value;
cout << "Enter the number of values to insert: ";
cin >> size;
for (int i = 0; i < size; i++) {
cout << "Enter value " << i + 1 << ": ";
cin >> value;
root = insert(root, value);
}
cout << "\nBinary Tree: ";
printTree(root);
cout << endl;
return 0;
}
