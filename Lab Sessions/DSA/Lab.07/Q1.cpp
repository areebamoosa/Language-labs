// Implement non-recursive version of quick sort algorithm using stack.

#include<iostream>
#include<stack>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp; 
}

int partition(int arr[], int st, int end){
    int idx = st - 1;
    int pivot = arr[end];

    for (int j = st; j < end; j++){
        if ( arr[j] <= pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSortIterative(int arr[], int n){
    stack<int> s;

    int st = 0;
    int end = n - 1;

    s.push(st);
    s.push(end);

    while (!s.empty()){
        end = s.top();
        s.pop();

        st = s.top();
        s.pop();

        // Partition the array
        int pivotIdx = partition(arr, st,end);

        // If there are elements on left side of pivot, push that range
        if ( pivotIdx - 1 > st){
            s.push(st);
            s.push(pivotIdx - 1);
        }

        // If there are elements on right side of pivot, push that range
        if (pivotIdx + 1 < end){
            s.push(pivotIdx + 1);
            s.push(end);
        }
    }
}

int main(){

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i =0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSortIterative(arr, n);

    cout << "Sorted array: ";
    for (int i =0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}