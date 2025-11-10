// The thief has found himself a new place for his thievery again. There is only one entrance to this
// area, called root. Besides the root, each house has one and only one parent house. After a tour,
// the smart thief realized that all houses in this place form a binary tree. It will automatically
// contact the police if two directly-linked houses were broken into on the same night. Given the
// root of the binary tree, return the maximum amount of money the thief can rob without alerting
// the police.

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

    // Insert Node Function
    void insertNode(int val){
        Node *newNode = new Node(val);

        if (root == NULL){
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            Node *current = q.front();
            q.pop();

            if (current->left == NULL){
                current->left = newNode;
                return;
            }
            else{
                q.push(current->left);
            }

            if (current->right == NULL){
                current->right = newNode;
                return;
            }
            else{
                q.push(current->right);
            }
        }
    }

    int robHelper(Node* root, int& withoutRoot){
        
        if ( root == NULL){
            withoutRoot = 0;
            return 0;
        }

        int leftWithout = 0;
        int rightWithout = 0;

        int leftRob = robHelper(root->left, leftWithout);
        int rightRob = robHelper(root->right, rightWithout);

        int robRoot = root->data + leftWithout + rightWithout;

        withoutRoot = (leftRob > leftWithout ? leftRob : leftWithout) + (rightRob > rightWithout ? rightRob : rightWithout);

        return (robRoot > withoutRoot ? robRoot : withoutRoot);

    }

    int rob(Node* root){
        int withoutRoot = 0;
        return robHelper(root, withoutRoot);
    }
};

int main(){

    BinaryTree tree;
    int n, val;

    cout << "Enter number of houses (nodes): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter money in house " << i + 1 << ": ";
        cin >> val;
        tree.insertNode(val);
    }

    int maxMoney = tree.rob(tree.root);
    cout << "\nMaximum money the thief can rob without alerting the police: " << maxMoney << endl;

    return 0;
}