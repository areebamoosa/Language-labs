// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a
// binary tree and inorder is the inorder traversal of the same tree, construct and return the binary
// tree.
// Input : preorder = [3,9,20,15,7] , Inorder = [9,3,15,20,7]
// Output : [3,9,20,null,null,15,7]

#include<iostream>
#include<vector>
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

// This function finds the root value in inorder array, so we know where the left & right subtrees begin & end
int findIndex(vector<int>& inorder, int start, int end, int value){
    for (int i = start; i <= end; i++){
        if(inorder[i] == value){
            return i;
        }
    }
    return -1;
} 

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int &preIndex){

    if ( start > end){
        return NULL;
    }

    Node* root = new Node(preorder[preIndex]); // preorder -> root , left , right => so here we take the first index root from preOrder
    preIndex++;

    if (start == end){
        return root; // If the node is leaf child simply return the node
    }

    // Pos of root value 
    int pos = findIndex(inorder,start, end, root->data);

    root->left = buildTree(preorder, inorder, start, pos-1, preIndex); // Building left subtree
    root->right = buildTree(preorder, inorder, pos+1, end, preIndex); // Building right subtree

    return root;
}

void printTree(Node* root) {
    
    if (!root) {
        cout << "[]";
        return;
    }

    queue<Node*> q;
    q.push(root);
    cout << "[";

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr != NULL) {
            cout << curr->data;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null";
        }

        if (!q.empty())
            cout << ",";
    }

    cout << "]";
}


int main(){

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, inorder.size() - 1, preIndex);

    printTree(root);

    return 0;
}