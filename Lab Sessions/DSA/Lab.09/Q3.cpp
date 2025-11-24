// Given two nodes of a binary search tree, return their least common ancestor.

// LCA : You are given two nodes in a BST : You need to find the lowest (closest) node that is the parent of BOTH

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

class BST{
public:
    Node* root;

    BST(){
        root = NULL;
    }

    Node* insertNode(Node* root, int val){
        if(root == NULL){
            return new Node(val);
        }

        if(val < root->data){
            root->left = insertNode(root->left, val);
        }
        else if(val > root->data){
            root->right = insertNode(root->right, val);
        }

        return root;
    }

    Node* LCA(Node* root, int n1, int n2){

        if(root == NULL){
            return NULL;
        }

        // If both nodes are smaller → go left
        if(n1 < root->data && n2 < root->data){
            return LCA(root->left, n1, n2);
        }

        // If both nodes are larger → go right
        if(n1 > root->data && n2 > root->data){
            return LCA(root->right, n1, n2);
        }

        // Otherwise this node is the LCA
        return root;
    }
};

int main(){

    BST tree;

    tree.root = tree.insertNode(tree.root, 20);
    tree.root = tree.insertNode(tree.root, 10);
    tree.root = tree.insertNode(tree.root, 30);
    tree.root = tree.insertNode(tree.root, 5);
    tree.root = tree.insertNode(tree.root, 15);
    tree.root = tree.insertNode(tree.root, 25);
    tree.root = tree.insertNode(tree.root, 35);

    int n1 = 5;
    int n2 = 15;

    Node* lca = tree.LCA(tree.root, n1, n2);

    if(lca != NULL){
        cout << "Least Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    }

    return 0;
}
