// AVL Tree Implementation

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
    int height;

    Node(int d){
        data = d;
        left = right = NULL;
        height = 1;
    }
};

class AVL{
    public:

    Node* root;

    AVL(){
        root = NULL;
    }

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

        if (balance > 1 ){
            if (balanceFactor(node->left) < 0 ){
                node->left = rotateLeft(node->left);
            }

                return rotateRight(node);
            
        }

        if (balance < -1){
            if (balanceFactor(node->right) > 0){
            node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;

    }

    Node* insert (Node* root, int key){

        if ( root == NULL){
            return new Node(key);
        }

        if (root->data > key){
            root->left = insert(root->left, key);
        }

        else if (root->data < key){
            root->right = insert(root->right,key);
        } 

        else {
            return root;
        }

        updateHeight(root);
        return balance(root);

    }

    Node* deleteNode(Node* root, int key){

        if (root == NULL){
            return root;
        }

        if (key > root->data){
            root->right = deleteNode(root->right, key);
        }

        else if (key < root->data){
            root->left = deleteNode(root->left,key);
        }

        else {

            // No child
            if (root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // One child
            else if (root->left == NULL || root->right == NULL){
                Node* temp = root->left? root->left : root->right;
                delete root;
                return temp;
            }

            // Two child

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            
        }

        updateHeight(root);
        return balance(root);

    }

    Node* minValueNode(Node* node){
        Node* current = node;

        while(current != NULL && current->left != NULL){
            current = current->left;
        }
        return current;
    }

    void inorder(Node* root){

        if (root == NULL){
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);

    }

};

int main(){

    AVL tree;

    tree.root = tree.insert(tree.root,10);
    tree.root = tree.insert(tree.root,20);
    tree.root = tree.insert(tree.root,30);

    cout << "Traversal" << endl;

    tree.inorder(tree.root);



    return 0;
}