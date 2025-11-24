// Given the root of a binary search tree, recursively find the sum of all nodes of the tree.

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class BinaryST{
    public:

    Node* root;

    BinaryST(){
        root = NULL;
    }

    Node* insertNode(Node* root, int val){

        if (root == NULL){
            return new Node(val);
        }

        if (val > root->data){
            root->right = insertNode(root->right, val);
        } else if (val < root->data){
            root->left = insertNode(root->left, val);
        } 
        return root;
    }

   int sum(Node* root){
    if (root == NULL){
        return 0;
    }

    return root->data + sum(root->left) + sum(root->right);

   }

};


int main(){

    BinaryST BST;

    BST.root =  BST.insertNode(BST.root, 5);
    BST.root =  BST.insertNode(BST.root, 25);
    BST.root =  BST.insertNode(BST.root, 15);

    cout << "Sum of all nodes of the tree " << BST.sum(BST.root) << endl;

    return 0;
}