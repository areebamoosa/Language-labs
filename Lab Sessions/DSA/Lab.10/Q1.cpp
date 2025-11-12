// Complete implementation of AVL tree given in Example 01 by implementing Insert and Delete
// methods.

#include<iostream>
using namespace std;

class AVLTree{
    private:

    struct Node{
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int val){
            data = val;
            left = right = nullptr;
            height = 1;
        }
    };

    Node* root;

    int height(Node* node){
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node){
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node* node){
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* balance(Node* node){
        updateHeight(node);

        int balance = balanceFactor(node);

        if ( balance > 1){
            if (balanceFactor(node->left) < 0){
                node->left =  rotateLeft(node->left);
                return rotateRight(node);
            }
        }
    }

};

int main(){
    return 0;
}