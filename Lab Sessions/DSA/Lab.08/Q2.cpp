// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its
// center).
// Input : root = [1,2,2,3,4,4,3]
// Output : true

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

    // Inserting Nodes Function
    void insertNode(int data){
        Node* newNode = new Node(data);

        if (root == NULL){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            if(current->left == NULL){
                current->left = newNode;
                return;
            } else{
                q.push(current->left);
            }
            if(current->right == NULL){
                current->right = newNode;
                return;
            } else{
                q.push(current->right);
            }
        }
    }

    bool isSymmetric(){
        if (!root) return true; // If tree is empty return true

        return isMirror(root->left, root->right); 
    }

    private: 

    bool isMirror(Node* a, Node* b){
        if (!a && !b) return true; // If both null, so they are symmetric
        if (!a || !b) return false; // If only one null, then they are not symmetric
        if (a->data != b->data) return false; // If values of nodes do not match, then they are not symmetric

        return isMirror(a->left , b->right) && isMirror(a->right, b->left); // This recursively checks the left subtree and the right subtree
    }

};

int main(){

    BinaryTree t;

    t.insertNode(1);
    t.insertNode(2);
    t.insertNode(2);
    t.insertNode(3);
    t.insertNode(4);
    t.insertNode(4);
    t.insertNode(3);

    if (t.isSymmetric())
        cout << "true";
    else
        cout << "false";

    return 0;
}