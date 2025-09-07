// Finding a targeted value in a sorted mxn matrix
// Time Complexity of the solution must be O(log (m*n))

#include <iostream>
using namespace std;

int targetSearch(int arr[][4], int rows, int cols, int tar){
    int st = 0;
    int end = rows * cols - 1;

    while (st <= end){
        int mid = st + (end - st) / 2;

        // Converting mid index to row and col
        int row = mid / cols;
        int col = mid % cols;

        if (arr[row][col] > tar){
            end = mid - 1;
        }
        else if (arr[row][col] < tar){
            st = mid + 1;
        }
        else{
            cout << "Target value found at row " << row << ", & column " << col << endl;
            return true;
        }
    }
    return false;
}

int main(){

    int arr[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    int target = 20;

    if (!targetSearch(arr, rows, cols, target)){
        cout << "Target value not found in the matrix." << endl;
    }

    return 0;
}