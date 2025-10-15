// Write a program using stack for checking whether a string is palindrome or not.

#include<iostream>
using namespace std;

class stack{
    char *arr;
    int top;
    int size;

    public:

    stack(int n){
        size = n;
        arr = new char[size];
        top = -1;
    }

    void push(int ch){
        if ( top < size - 1){
            arr[++top] = ch;
        }
    }

    int pop(){
        if (top >= 0){
            return arr[top--];
        }

        return -1;
    }

    bool isEmpty(){
        return top == -1;
    }
};

bool isPalindrome(string str){

    stack s(str.length()); // Size of stack same as size of string passed

    for (int i =0; i < str.length(); i++){
        s.push(str[i]);
    }

    // Comparing each char of str with popping of elemets from stack

    for (int i =0; i < str.length(); i++){
        if (str[i] != s.pop()){
            return false;
        }
    }
    return true;
}

int main(){

    string word;
    cout << "Enter a string : " << endl;
    cin >> word;

    if (isPalindrome(word)){
        cout << "The given string is Palindrome" << endl;
    } else {
        cout << "The given string is not Palindrome" << endl;
    }

    return 0;
}