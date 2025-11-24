// Implement Heap Sort

#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if ( leftChild < n && arr[leftChild] > arr[largest] ){
        largest = leftChild;
    }

    if ( rightChild < n && arr[rightChild] > arr[largest] ){
        largest = rightChild;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for (int i = (n/2) - 1; i >= 0; i--){
        heapify(arr,n , i);
    }
}

void heapSort(int arr[], int n){
    
    buildHeap(arr,n);

    for (int i =  n-1; i >0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i, 0);
    }
}

void printArray(int arr[], int n){
    for (int i =0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[] = {15, 5, 10, 2, 4, 3};
    int n = 6;

    cout << "Original Heap" << endl;
    printArray(arr, n);

    cout << "Heap after sorting" << endl;
    heapSort(arr,n);
    printArray(arr,n);

    return 0;
}