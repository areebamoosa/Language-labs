// Given an integer array nums where the elements are sorted in ascending order, convert it to a
// height-balanced binary search tree.
// Input : nums = [-10, -3, 0, 5, 9]
// Output : [0, -3, 9, -10, null, 5]

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

TreeNode* arrayToBalanced(int nums[], int start, int end){
    if (start > end){
        return NULL;
    }

    int mid = start + (end - start + 1)  / 2;

    TreeNode* root = new TreeNode (nums[mid]);

    root->left = arrayToBalanced(nums, start, mid - 1);
    root->right = arrayToBalanced(nums, mid + 1, end);

    return root;
}

void preOrder(TreeNode* root){
    if ( root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    int nums[] = {-10, -3, 0, 5, 9};
    int n = 5;

    TreeNode* root = arrayToBalanced(nums, 0, n - 1);

    cout << "Array to Balanced Binary Search Tree : ";
    preOrder(root);

    return 0;
}