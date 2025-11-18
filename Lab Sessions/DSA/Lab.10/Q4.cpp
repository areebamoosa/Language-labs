// Given the root of a BST, find its diameter.

#include<iostream>
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

TreeNode* insertBST(TreeNode* root, int val) {

    if (root == NULL) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }

    return root;
}

int height(TreeNode* root) {

    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int Diameter(TreeNode* root) {

    if (root == NULL) return 0;

    int hLeft = height(root->left);
    int hRight = height(root->right);

    int dLeft = Diameter(root->left);
    int dRight = Diameter(root->right);

    int dThroughRoot = hLeft + hRight + 1;

    if (dThroughRoot > dLeft && dThroughRoot > dRight){
        return dThroughRoot;
    }
    else if  (dLeft > dRight){
        return dLeft;
    }

    else{
        return dRight;
    }
}


int main(){
    TreeNode* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    for (int i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }

    cout << "Diameter of BST = " << Diameter(root) << endl;

    return 0;
}