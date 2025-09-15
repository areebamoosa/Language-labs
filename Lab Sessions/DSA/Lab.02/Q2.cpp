// Q2: Remove duplicates from sorted list.
// Task : Delete all duplicates from a sorted linkedlist, leaving only distinct numbers.

#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int v){
        val = v;
        next = NULL;
    }
};

class linkedList{
    Node* head;

    public:

    linkedList(){
        head = NULL;
    }

    // Inserting a node in linkedlist
    void insertLL(int v){
        Node* newNode = new Node(v);

        if (head == NULL){
            head = newNode;
            return;
        } else {
            Node* temp = head;
            while ( temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

    }

    // Function to remove duplicates from linkedlist
    Node* removeDuplicates(){

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

        while (curr != NULL){
            next = curr->next;

            if ( next!= NULL && curr->val == next->val){
                Node* dup = next;
                curr->next = next->next;
                delete dup;
            } else{
                prev = curr;
                curr = next;
            }
        }
        return head;
    }

    // Printing linked List
    void printll(){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
};

int main(){
    linkedList ll;

    ll.insertLL(1);
    ll.insertLL(2);
    ll.insertLL(2);
    ll.insertLL(3);

    // Before removing duplicates
    cout << "Before removing duplicates, the linkedlist is : \n";
    ll.printll();

    // After removing duplicates
    cout << "After removing duplicates from the linkedlist : \n";
    ll.removeDuplicates();
    ll.printll();

    return 0;
}