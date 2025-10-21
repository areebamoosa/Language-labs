#include<iostream>
using namespace std;

void bubbleeSort(int arr[], int n){
    int i,j;
    bool swapped;

    for (int i = 0; i < n-1; i++){
        swapped = false;

        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void printArray(int arr[], int n){
    for (int i =0; i <n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[] = {5,1,4,2,8};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleeSort(arr, n);

    cout << "Sorted Array : " << endl;
    printArray(arr,n);

    return 0;
}