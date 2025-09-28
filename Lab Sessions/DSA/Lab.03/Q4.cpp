// Q4: Sort the contents of list N created in question 4 in descending order

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

    // Sorting the list in descending order
    Node* sortList(Node* list){
        if (list == NULL || list->next == NULL) return list;

        Node* i = list;
        while (i != NULL){
            Node* j = i->next;
            while (j != NULL){
                if ( i->data < j->data){
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
        return list;
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

    // Concatenate L and M into N
    N.head = N.concatLinkedlists(L.head, M.head);

    cout << "List N (Concatenated): ";
    N.printLL(N.head);

    cout << "Sorting the Concatenated list N in descending order: " << endl;
    N.head = N.sortList(N.head);
    N.printLL(N.head);

    return 0;
}