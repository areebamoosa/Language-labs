
#include<iostream>
#include<stack>
using namespace std;

class TreeNode{
    public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

class BinarySearchTree{
    public:

    TreeNode* root;

    BinarySearchTree(){
        root = NULL;
    }

    TreeNode* insert(TreeNode* root, int val){
    if (root == NULL){
        return new TreeNode (val);
    }

    if ( val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
    }


    // Pre Order
    void preorder(TreeNode* root){

        if (root == NULL){
            return;
        }

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();

            cout << curr->data << " ";

            if (curr->right != NULL){
                s.push(curr->right);
            }
            if (curr->left != NULL){
                s.push(curr->left);
            }
        }

    }

    // Post order
    void postorder(TreeNode* root){
        if (root == NULL){
            return;
        }

        stack<TreeNode*> s1,s2;
        s1.push(root);

        while (!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();

            s2.push(curr);

            cout << curr->data << " ";

            if (curr->left != NULL){
                s1.push(curr->left);
            }
            if (curr->right != NULL){
                s1.push(curr->right);
            }
        }

        while(!s2.empty()){
            cout << s2.top()->data << " ";
            s2.pop();
        }

    }




};

int main(){
    return 0;
}