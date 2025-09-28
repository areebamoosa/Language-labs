// Q2 : Implement class of double ended queue using doubly Linkedlist.

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class Dequeue{
    Node* front;
    Node* rear;

    public:

    Dequeue(){
        front = rear = NULL;
    }

    // Insert at front function
    void insertFront(int data){
        Node* newNode = new Node(data);

        // If list is empty
        if (front == NULL){
            front = rear = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            return;
        }

        // If list have nodes
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
        front->prev = NULL;
    }

    // Insert at rear function
    void insertRear(int data){
    Node* newNode = new Node(data);

    // If list is empty
    if (front == NULL){
        front = rear = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }

    // If list have nodes
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
    }

    // Delete at Front function
    void deleteFront(){

        // If list is empty
        if ( front == NULL){
            cout << "List is empty" << endl;
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
        temp->next = NULL;
        front->prev = NULL;
        delete temp;
    }

    // Delete at Back function
    void deleteBack(){

        // If list is empty
        if ( front == NULL){
            cout << "List is empty" << endl;
            return;
        }

        // If list have one node
        if (front == rear){
            delete front;
            front = rear = NULL;
            return;
        }

        // If list have more than one node
        Node* temp = rear;
        rear = temp->prev;
        rear->next = NULL;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    // Peek Front function
    int peekFront(){

    if (front == NULL){
        cout << "List is empty" << endl;
        return -1;
    }
    return front->data;
    }

    // Peek Back function
    int peekBack(){

    if (front == NULL){
        cout << "List is empty" << endl;
        return -1;
    }
        return rear->data;
    }

    bool Empty(){
        return front == NULL;
    }

    void printLL(){

        if (front == NULL){
        cout << "List is empty" << endl;
        return;
       }

        Node* temp = front;

        while ( temp!= NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main(){

    Dequeue dq;

    dq.insertFront(1);
    dq.insertFront(2);
    dq.insertFront(3);

    dq.insertRear(4);
    dq.insertRear(5);
    dq.insertRear(6);

    dq.deleteFront();

    dq.deleteBack();

    cout << "Front = " << dq.peekFront() << endl;
    cout << "Back = " << dq.peekBack() << endl;

    dq.printLL();

    return 0;
}