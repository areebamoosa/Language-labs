// Q1 : Merge two sorted lists
// Task : Given the heads of two sorted linked lists, list1 and list2, merge them into one sorted list.

#include<iostream>
using namespace std;


class listNode{
    public :

    int val;
    listNode* next;

    listNode(int v){
        val = v;
        next = NULL;
    }
};

class mergeList {
    public:

    listNode* mergedList (listNode* list1, listNode* list2){

    listNode dummy(0);
    listNode* tail = &dummy;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1!= NULL){
        tail->next = list1;
    } else {
        tail->next = list2;

    }
    return dummy.next;
}
};

void printList(listNode* temp){
    while (temp!=NULL){
        cout << temp->val << " -> ";
        temp = temp->next;

    }
    cout << "NULL" << endl;
}



int main(){

    // Creating first sorted list : list1
    listNode* list1 = new listNode(1);
    list1->next = new listNode(3);
    list1->next->next = new listNode(5);
    list1->next->next->next = new listNode(7);

    // Creating second sorted list : list2

    listNode* list2 = new listNode(2);
    list2->next = new listNode(4);
    list2->next->next = new listNode(6);
    list2->next->next->next = new listNode(8);

    mergeList ll;
    listNode* merged = ll.mergedList(list1, list2);

    cout << "Merged Sorted list : \n";
    printList(merged);

    return 0;
}