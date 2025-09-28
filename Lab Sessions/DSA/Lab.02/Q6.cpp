// Q6 : Circular Queue (FIFO: First In, First Out) using Linked List
// You need two pointers: front and rear.
// Enqueue (insert) = insert at rear, move rear, and connect rear->next = front.
// Dequeue (remove) = remove from front, move front, and make sure rear->next = front.

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

class Queue{
    Node* front;
    Node* rear;

    public:

    Queue(){
        front = rear = NULL;
    }

    // Enqueue function : Push a new node at rear and then update rear the connect it to head to make it circular
    void enqueue(int data){
        Node* newNode = new Node(data);

        if (front == NULL){
            front = rear = newNode;
            rear->next = front;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    // Dequeue function : delete the front node then update the next node as front and make sure the rear's next pointer must point to the front

    void dequeue(){
        if (front == NULL){
            cout << "The list is empty so no node can be deleted" << endl;
            return;
        }

        if ( front == rear){
            delete front;
            front = rear = NULL;
            return;
        }

        Node* temp = front;
        front = temp->next;
        rear->next = front;
        temp->next = NULL;
        delete temp;
    }

    // Print ll function
    void printll(){

        if (front == NULL){
        cout << "Queue is empty" << endl;
        return;
        }

        Node* temp = front;
        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp!=front);
         cout << "(back to " << front->data << ")";
    }
};

int main(){
    Queue qq;
    
    qq.enqueue(5);
    qq.enqueue(4);
    qq.enqueue(3);
    qq.enqueue(2);
    qq.enqueue(1);

    cout << "Original linkedlist : " << endl;
    qq.printll();


    cout << "After dequeue function : " << endl;
    qq.dequeue();
    qq.printll();

    return 0;
}