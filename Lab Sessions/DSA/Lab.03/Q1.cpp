// Q1: Implement class of a Circular Queue using a circular linkedlist

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class circularQueue{
    Node* front;
    Node* rear;

    public:

    circularQueue(){
        front = rear = NULL;
    }

    // Enqueue function : inserting at rear
    void push(int val){
        Node* newNode = new Node(val);

        // If list is empty
        if ( front == NULL){
            front = rear = newNode;
            newNode->next = front;
            return;
        }

        // If list have nodes
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    // Dequeue function : deleting element at front
    void pop(){

        // If list is empty
        if ( front == NULL){
            cout << "The list is empty, so no node can be popped" << endl;
            return;
        }

        // If list have one node
        if (front == rear){
            delete front;
            front = rear = NULL;
            return;
        }

        // If list have more than one node
        Node* temp = front;
        front = temp->next;
        rear->next = front;
        temp->next = NULL;
        delete temp;
    }

    // Peek front fuction : returns front's data
    int peekFront(){

        if (front == NULL){
        cout << "Queue is empty" << endl;
        return -1;
        }
        return front->data;
    }

    // Peek rear fuction : returns front's data
    int peekRear(){

        if (rear == NULL){
        cout << "Queue is empty" << endl;
        return -1;
       }
        return rear->data;
    }

    // Function to print the Circular queue linkedlist
    void printll(){

    if (front == NULL){
    cout << "Queue is empty" << endl;
    return;
    }
        Node* temp = front;

        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        } while ( temp != front);
        cout << "(back to " << front->data << " )" << endl;
    }

    bool Empty(){
        return front == NULL;
    }

};

int main(){

    circularQueue cq;

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);

    // Seeing elements of queue
    cout << "The elements in queue after pushing are : " << endl;
    cq.printll();

    // Popping one element
    cout << "The elements in queue after popping are : " << endl;
    cq.pop();
    cq.printll();

    // Accessing Front data node
    cout << "The Front value is : " << cq.peekFront() << endl;

    // Accesing Rear data node
    cout << "The Rear value is : " << cq.peekRear() << endl;

    return 0;
}