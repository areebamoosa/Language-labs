// Given the head of a singly linked list where elements are sorted in ascending order, convert it
// to a height-balanced binary search tree.

#include<iostream>
using namespace std;

class ListNode{
    public:

    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

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

void insertNode(ListNode* &head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

// Converting sorted array into BST
TreeNode* buildBST(int arr[], int start, int end){
    if (start > end){
        return NULL;
    }

    int mid = ( start + end ) / 2;

    TreeNode* root = new TreeNode (arr[mid]);

    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);

    return root;
}

// Converting linkedlist into an array
int listToArray(ListNode* head, int arr[]){
    int i = 0;

    while(head != NULL){
        arr[i++] = head->data;
        head = head->next;
    }
    return i;
}

void inorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main(){

    ListNode* head = NULL;

    insertNode(head, -10);
    insertNode(head, -3);
    insertNode(head, 0);
    insertNode(head, 5);
    insertNode(head, 9);

    int arr[100];
    int n = listToArray(head, arr);

    TreeNode* root = buildBST(arr, 0, n - 1);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}