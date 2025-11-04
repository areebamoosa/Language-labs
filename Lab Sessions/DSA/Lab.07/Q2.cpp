// Implement non-recursive version of the merge sort algorithm.

#include <iostream>
#include <vector>
using namespace std;

// To combine two already sorted halves of the array into one single sorted array
void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    // Copying  the sorted elements to original array
    for (int idx = 0; idx < temp.size(); idx++){
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int>& arr) {
    int n = arr.size();

    for (int size = 1; size < n; size *= 2) {
        for (int st = 0; st < n - size; st += 2 * size) {
            int mid = st + size - 1;
            int end = min(st + 2 * size - 1, n - 1);

            merge(arr, st, mid, end);
        }
    }
}

int main(){

    vector<int> arr = {38, 27, 43, 10, 82, 9, 3};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}