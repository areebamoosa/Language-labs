// Q3 : SortList (MergeSort)
// Task : Sort a linkedlist in ascending order using Merge Sort

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
    void push_back(int data){
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

    // Finding Middle Element
    Node* middleEl(Node* head){
        if ( head == NULL || head->next == NULL){
            return head;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    //Merging two sorted lists

    Node* merge(Node* l1, Node* l2){
        Node dummy(0);
        Node* tail = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->data < l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != NULL) {
            tail->next = l1;
        }
        else {
        tail->next = l2;
        }
        return dummy.next;
    }

    // Merge Sort function
    Node* mergeSortFunc(Node* head){
        if (head == NULL || head->next == NULL){
            return head;
        }

        Node* mid = middleEl(head);
        Node* rightHalf = mid->next;
        mid->next = NULL;

        Node* left = mergeSortFunc(head);
        Node* right = mergeSortFunc(rightHalf);

        return merge(left, right);
    }

    // Sorting list
    void mergeSort() {
        head = mergeSortFunc(head);
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
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(4);
    ll.push_back(2);

    cout << "Before sorting: ";
    ll.printll();

    ll.mergeSort();

    cout << "After sorting: ";
    ll.printll();

    return 0;
}