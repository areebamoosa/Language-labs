// Given an array nums with n objects colored red, white, or blue, sort them inplace so that
// objects of the same color are adjacent, with the colors in the order red, white, and blue. We
// will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively. You
// must solve this problem by writing a sort function.
// Example 1: Input: nums = [2,0,2,1,1,0], Output: [0,0,1,1,2,2]
// Example 2: Input: nums = [2,0,1], Output: [0,1,2]

#include<iostream>
using namespace std;

class Sort{
    int *arr;
    int size;

    public:

    Sort(int s){
        size = s;
        arr = new int[size];
    }

    void inputArray(){
        cout << "Enter : " << size << " elements ( 0, 1 or 2) \n" ;
        for (int i =0; i < size; i++){
            cin >> arr[i];
        }
    }

    void sortColors(){
        int low = 0;
        int mid = 0;
        int high = size - 1;

        while (mid <= high){
            if (arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if ( arr[mid] == 1){
                mid++;
            } else { // arr[mid] == 2
               swap(arr[high], arr[mid]);
               high--;
            }
        }

    }

    void print(){
        for (int i =0; i < size; i ++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){

    int n;
    cout << "Enter size of array : ";
    cin >> n;

    Sort s(n);
    s.inputArray();
    s.sortColors();

    cout << "Sorted Colors array : " << endl;
    s.print();

    return 0;
}