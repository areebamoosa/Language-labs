// Implement a data structure, that checks if the last k integers parsed in the stream are equal to value.

#include <iostream>
#include <vector>
using namespace std;

class DataStream{
    vector<int> nums;
    int value;
    int k;

public:
    DataStream(int value, int k){
        this->value = value;
        this->k = k;
    }

    bool consec(int num){
        nums.push_back(num);

        if (nums.size() < k)
            return false;

        for (int i = nums.size() - k; i < nums.size(); i++){
            if (nums[i] != value){
                return false;
            }
        }
        return true;
    }
};

int main(){

    DataStream ds(4, 3);

    cout << ds.consec(4) << endl;
    cout << ds.consec(4) << endl; 
    cout << ds.consec(4) << endl;
    cout << ds.consec(3) << endl; 

    return 0;
}