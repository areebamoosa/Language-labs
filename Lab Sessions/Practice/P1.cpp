// Heap sort using max heap

#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[leftchild] < arr[largest]){
        largest = leftchild;
    }
    if (rightchild < n && arr[rightchild] < arr[largest]){
        largest = rightchild;
    }

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildHeap(int arr[], int n){
    for (int i = n / 2 -1; i >= 0; i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr,n);

    for (int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    return 0;
}