// Design your implementation of circular double ended queue.

#include<iostream>
using namespace std;

class MyCircularDeque{
    int *arr;
    int size;
    int front;
    int rear;

    public:

    MyCircularDeque(int k){
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Insert front function
    bool insertFront(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[front] = x;
            return true;
        }
        if (isFull()){
            return false;
        }
        front = (front - 1 + size) % size;
        arr[front] = x;
        return true;

    }

    // Insert last function
    bool insertLast(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = x;
            return true;
        }
        if (isFull()){
            return false;
        }
        rear = (rear + 1 ) % size;
        arr[rear] = x;
        return true;
    }

    // Delete front function
    bool deleteFront(){
        if(isEmpty()){
            return false;
        }
        if ( front == rear){
            front = rear = -1;
            return true;

        }
        front = ( front + 1 ) % size;
        return true;
    }

    // Delete rear function
    bool deleteRear(){
        if(isEmpty()){
            return false;
        }
        if ( front == rear){
            front = rear = -1;
            return true;
        }
        rear = ( rear - 1 ) % size;
        return true;
    }

    // Getting front element 
    int getFront(){
        if ( isEmpty()){
            cout << "Circular Deque is Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    // Getting rear element 
    int getRear(){
        if ( isEmpty()){
            cout << "Circular Deque is Empty" << endl;
            return -1;
        }

        return arr[rear];
    }

    // Array is Empty
    bool isEmpty(){
        return front == -1;
    }

    // Array is Full
    bool isFull(){
        return front == (rear + 1) % size;
    }

};

int main(){

    MyCircularDeque cq(3);

    cout << boolalpha; // This makes cout print true/false instead of 1/0

    cout << "insertLast(1): " << cq.insertLast(1) << endl;
    cout << "insertLast(2): " << cq.insertLast(2) << endl;
    cout << "insertFront(3): " << cq.insertFront(3) << endl;
    cout << "insertFront(4): " << cq.insertFront(4) << endl; 

    cout << "Rear element: " << cq.getRear() << endl;
    cout << "Is full? " << cq.isFull() << endl;

    cout << "deleteRear(): " << cq.deleteRear() << endl;
    cout << "insertFront(4): " << cq.insertFront(4) << endl;

    cout << "Front element: " << cq.getFront() << endl;

    return 0;
}