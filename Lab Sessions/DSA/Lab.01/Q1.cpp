// Write a C++ program to copy data of a 2D array in a 1D array using Column Major Order.

#include<iostream>
using namespace std;

int main(){

    // 2D array
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 1D array
    int arr1D[6];
    int k = 0;

    //Assigning values of 2D array in 1D array using Column major Order
    for(int i = 0; i<3; i++){ // Columns
        for(int j = 0; j < 2; j++){ // Rows
             arr1D[k] = arr2D[j][i];
             k++;
        }
    }

    // Printing elements of 1D array
    for (int l = 0; l < 6 ; l++){
        cout << arr1D[l] << " ";
    }
    cout << endl;

    return 0;
}