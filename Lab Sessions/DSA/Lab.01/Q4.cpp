// Binary Search : Searching target value in an array

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int tar){

    int st = 0;
    int end = n - 1;

    while (st <= end){
        int mid = st + (end - st) / 2;

        if (arr[mid] > tar){
            end = mid - 1;
        }
        else if (arr[mid] < tar){
            st = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){

    int nums[5] = {1, 2, 3, 4, 5};
    int target = 4;
    int n = sizeof(nums) / sizeof(nums[0]);

    int index = binarySearch(nums, n, target);

    cout << "Target value found at index: " << index << endl;

    return 0;
}