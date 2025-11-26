// Detect a cylic structure

#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

bool hasCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if ( slow == fast){
            return true;
        }
    }
    return false;
}

void checkCyle(Node* head){

    if (hasCycle(head)){
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

}

int main(){

    Node* a = new Node(5);
    Node* b = new Node(5);
    Node* c = new Node(5);
    Node* d = new Node(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    checkCyle(a);

    return 0;
}
