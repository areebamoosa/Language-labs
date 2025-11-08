// Given a binary tree, determine if it is height-balanced i.e., the absolute difference between the
// left and right subtree of each node is not greater than 1.

#include<iostream>
#include<queue>
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

class BinaryTree{
    public:

    Node* root;

    BinaryTree(){
        root = NULL;
    }

    void insertNode(int data){
        Node* newNode = new Node(data);

        if (root == NULL){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();

            if (curr->left == NULL){
                curr->left = newNode;
                return;
            } else {
                q.push(curr->left);
            }
            if(curr->right == NULL){
                curr->right = newNode;
                return;
            } else{
                q.push(curr->right);
            }
        }

    }

    // Function for measuring the Height of tree 
    int height(Node* node){

        if (node == NULL){
            return 0; // Base case : Empty tree has height 0
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight); // 1 ( the org node ) + (the height of taller side)
    }

    // Function for checking if the subtrees are balanced 
    bool isBalanced(Node* node){
        if ( node == NULL){
            return true; // If tree is empty then it's balanced already
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        int diff = abs(leftHeight - rightHeight);

        if (diff <= 1 && isBalanced(node->left) && isBalanced(node->right)){
            return true;
        }

        return false;
    }
};

int main(){

    BinaryTree tree;

    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);

    cout << (tree.isBalanced(tree.root) ? "true" : "false") << endl;

    return 0;
}