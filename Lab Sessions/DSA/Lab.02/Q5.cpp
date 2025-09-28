// Q5 : Stack (LIFO: Last In, First Out) using Linked List
// Top of stack = head of linked list.
// Push = insert at head.
// Pop = remove and return the value from head.
// Peek = return head’s data without deleting.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return head == NULL;
        }
    }

    // Push function
    void push(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    // Pop function
    int pop()
    {

        if (head == NULL)
        {
            cout << "The stack is empty so no value can be popped" << endl;
            return -1;
        }

        Node *temp = head;
        int poppedVal = head->data;
        head = temp->next;
        temp->next = NULL;
        delete temp;

        return poppedVal;
    }

    // Peek function
    int peek()
    {

        if (head == NULL)
        {
            cout << "The stack is empty, nothing to peek." << endl;
            return -1;
        }

        return head->data;
    }
};

int main()
{

    Stack st;

    // Pushing elemets on top of stack
    st.push(1);
    st.push(2);
    st.push(3);

    // Peeking top element of stack
    cout << "Top element (peek): " << st.peek() << endl;

    // Popping top element of stack
    cout << "Popping: " << st.pop() << endl;

    return 0;
}