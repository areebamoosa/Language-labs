// Q3: Create two doubly linkedlist L ad M. List L should be containing all even elements from 2 to 10 and list M should contain all odd elements from 1 to 9. Create a new list N by concatening list L and M.

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = prev = NULL;
    }
};

class doublyLinkedList{
    public:

    Node* head;

    doublyLinkedList(){
        head = NULL;
    }

    // Concatination of two linkedlists
    Node* concatLinkedlists(Node* list1, Node* list2){

        if ( list1 == NULL) return list2;
        if ( list2 == NULL) return list1;

        Node* temp = list1;

        while( temp->next!= NULL){
            temp = temp->next;
        }

        temp->next = list2;
        list2->prev = temp;

        return list1;

    }

    // Push back function
    void push_back(int data){
        Node* newNode = new Node(data);

        if ( head == NULL){
            head = newNode;
            return;
        }

        Node* temp = head;

        while ( temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Print ll function
    void printLL(Node* node){

        while ( node != NULL){
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << "NULL" << endl;
    }

};

int main(){

    doublyLinkedList L, M, N;

    // List L : Even numbers

    for (int i = 2; i <=10 ; i+=2){
        L.push_back(i);
    }

    // List M : Odd numbers

    for (int i = 1; i <=9 ; i+=2){
        M.push_back(i);
    }

    cout << "List L (Even): ";
    L.printLL(L.head);

    cout << "List M (Odd): ";
    M.printLL(M.head);

    // Concatenate L and M into N
    N.head = N.concatLinkedlists(L.head, M.head);

    cout << "List N (Concatenated): ";
    N.printLL(N.head);

    return 0;
}