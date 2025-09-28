// Q4: Check for Palindrome linkedlist
// Task : Return true if a linkedlist is a palindrome (reads the same forwards and backwards)

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

class linkedList{
    Node* head;
    Node* tail;

    public:

    linkedList(){
        head = tail = NULL;
    }

    // Pushback function
    void push_front(int data){
        Node* newNode = new Node(data);

        if (head == NULL){
            head = tail = newNode;
            return;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Reversing ll helper function
    Node* reverseLL(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Linked list Palindrome function
    bool isPalindrome(){

        if ( head == NULL || head->next == NULL){
            return head;
        }

        // Finding middle element through slow fast pointer approach
        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reversing secondhalf
        slow->next = reverseLL(slow->next);

        // Comparing first half and second half
        Node* first = head;
        Node* second = slow->next;

        while(second != NULL){
            if (first->data != second->data){
                return false;
            }
            first = first->next;
            second = second->next;
        } 
        return true;
    }

    //Printing ll
    void printll(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    linkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(2);
    ll.push_front(1);

    cout << "Original linkedlist : " << endl;

    ll.printll();

    if (ll.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}