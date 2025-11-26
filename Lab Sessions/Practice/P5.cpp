#include<iostream>
using namespace std;

int searchInrotatedArray(int arr[], int n, int target){
    int start = 0;
    int end =  n - 1;

    while ( start <= end){

        int mid = start + (end - start) / 2;

        if (arr[mid] == target){
            return mid;
        }

        if ( arr[start] <= arr[mid]){

            if (target >= arr[start] && target < arr[mid]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if ( target >= arr[mid] && target < arr[end]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

    }
    return -1;

}

int main(){

    int arr [] = {10,20,30,2,4,6,8};
    int n = 7;
    int target = 2;

    int index = searchInrotatedArray(arr,n,target);

    if (index!= -1){
    cout << "Element found at index: " << index << endl;

    } else {
    cout << "Element not found!" << endl;
    }

    return 0;
}