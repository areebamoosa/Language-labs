// Implement methods for the following operations in Binary tree class given in example 01.
// Searching a node based on a given value.
// Pre-order traversal
// Post-order traversal

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

    // In Binary Tree, it adds a new node in the first empty spot in the tree (level by level).
    // Function to insert a Node in a tree
    void insertNode(int data){
        Node* newNode = new Node(data);

        if(root == NULL){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            if(current->left == nullptr){
                current->left = newNode;
                return;
            } else{
                q.push(current->left);
            }

            if (current->right == nullptr) {
            current->right = newNode;
            return;

            } else {
                q.push(current->right);
            }

        }
    }

    // Preorder traversal
    void preOrder(Node* root){
        if ( root == NULL){
            return;
        }

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // PostOrder Traversal
    void postOrder(Node* root){
        if ( root == NULL){
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    // Searching a node
    bool Search(Node* root, int value){
        if (root == NULL){
            return false;
        }

        if (root->data == value){
            return true;
        }

        return Search(root->left, value) || Search(root->right, value);
    }
};

int main(){

    BinaryTree tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);

    cout << "Preorder: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "Postorder: ";
    tree.postOrder(tree.root);
    cout << endl;

    int value = 3;
    if (tree.Search(tree.root, value)){
        cout << value << " found in tree!" << endl;
    }
    else {
        cout << value << " not found in tree!" << endl;
    }

    return 0;
}