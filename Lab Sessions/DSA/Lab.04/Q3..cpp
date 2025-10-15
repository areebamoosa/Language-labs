// Given an array of distinct integers, return all the possible permutations.

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapNum(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        printArray(arr, end + 1);
        return;
    }

    for (int i = start; i <= end; i++) {
        swapNum(arr[start], arr[i]);
        permute(arr, start + 1, end);     
        swapNum(arr[start], arr[i]);      
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    cout << "All permutations are:\n";
    permute(arr, 0, n - 1);
}