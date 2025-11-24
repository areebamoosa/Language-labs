// Complete implementation of AVL tree given in Example 01 by implementing Insert and Delete
// methods.

#include <iostream>
using namespace std;

class AVLTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        int height;

        Node(int val)
        {
            data = val;
            left = right = nullptr;
            height = 1;
        }
    };

    Node *root;

    int height(Node *node)
    {
        return node ? node->height : 0;
    }

    int balanceFactor(Node *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node *node)
    {
        // This func recalculates how tall a node is by checking height of it's left & right children and adding 1 for itself
        node->height = 1 + max(height(node->left), height(node->right));
    }

    // Rotate func when left side of tree is too heavy
    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Rotate func when right side of tree is too heavy
    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node *balance(Node *node)
    {

        updateHeight(node);

        int balance = balanceFactor(node);

        // If result = 0 → perfectly balanced
        // If result = +2 → left-heavy
        // If result = −2 → right-heavy

        // Left heavy
        if (balance > 1)
        {
            if (balanceFactor(node->left) < 0) // Left-Right case
                node->left = rotateLeft(node->left);
            return rotateRight(node); // Left-Left case
        }

        // Right heavy
        if (balance < -1)
        {
            if (balanceFactor(node->right) > 0) // Right-Left case
                node->right = rotateRight(node->right);
            return rotateLeft(node); // Right-Right case
        }

        return node; // Balanced
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    Node *insert(Node *node, int key)
    {

        if (node == NULL)
        {
            return new Node(key);
        }

        if (key < node->data)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node; // Duplicate keys not allowed
        }

        updateHeight(node);

        return balance(node);
    }

    Node *deleteNode(Node *root, int key)
    {

        if (!root)
            return root;

        // Step 1: Normal BST delete
        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else
        {

            // Case 1: No child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL || root->right == NULL)
            {
                Node *temp = root->left ? root->left : root->right;
                delete root;
                return temp; // return the child upward
            }

            // Case 3: Two children
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        // Step 2: Update height
        updateHeight(root);

        // Step 3: Rebalance
        return balance(root);
    }

    void inOrder(Node *node)
    {
        if (!node)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }

    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
};

int main()
{

    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In-order traversal before deletion: ";
    tree.inOrder();

    tree.deleteKey(20);

    cout << "In-order traversal after deleting 20: ";
    tree.inOrder();

    return 0;
}