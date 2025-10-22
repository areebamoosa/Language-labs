// Given an array arr[ ] of length N consisting cost of N toys and an integer K the amount with
// you. The task is to find maximum number of toys you can buy with K amount.
// Test Case: Input: N = 7, K = 50, arr[] = {1, 12, 5, 111, 200, 1000, 10}, Output: 4
// Explanation: The costs of the toys. You can buy are 1, 12, 5 and 10.

#include<iostream>
#include <algorithm>
using namespace std;

int toys(int arr[], int n, int k){
    sort(arr, arr + n);
    int sum = 0;
    int toys = 0;

    for (int i = 0 ; i < n ; i++ ) {
        if ( sum + arr[i] <=  k){
        sum = sum + arr[i];
        toys++;
        } else {
        break;
        }
    }
    return toys;
}

int main(){

    int arr[] = {1,12,5,111,200,1000,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 50;

    cout << "Maximum number of toys you can buy: " << toys(arr, n, k) << endl;

    return 0;
}