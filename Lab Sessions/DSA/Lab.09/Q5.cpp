// Given the root of a Binary Search Tree (BST), return the minimum difference
// between the values of any two different nodes in the tree.

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

    int minDiffUtil(Node* root, int &prev, int &minDiff){
        
        if(root == NULL){
            return minDiff;
        }

        minDiffUtil(root->left, prev, minDiff);

        if(prev != -1){
            int diff = root->data - prev;
            if(diff < minDiff){
                minDiff = diff;
            }
        }

        prev = root->data;

        minDiffUtil(root->right, prev, minDiff);

        return minDiff;
    }

    int getMinimumDifference(Node* root){
        int prev = -1;        
        int minDiff = 999999;
        return minDiffUtil(root, prev, minDiff);
    }

};

int main(){

    BST tree;

    tree.root = tree.insertNode(tree.root, 10);
    tree.root = tree.insertNode(tree.root, 5);
    tree.root = tree.insertNode(tree.root, 15);
    tree.root = tree.insertNode(tree.root, 3);
    tree.root = tree.insertNode(tree.root, 7);

    cout << "Minimum difference between any two nodes: " << tree.getMinimumDifference(tree.root) << endl;

    return 0;
}