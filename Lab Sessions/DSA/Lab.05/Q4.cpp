// Algorithm that accepts a stream of integers and retrieves the product of last k integers of the stream. 

#include<iostream>
#include<vector>
using namespace std;

class ProductofNumbers{
    vector<int> nums;

    public: 

    void add(int num){
        nums.push_back(num);
    }

    int getProduct(int k){
        int Product = 1;

        for (int i = nums.size() - k; i < nums.size(); i++){
            Product = Product *  nums[i];
        }
        return Product;
    }
    
};

int main(){

    ProductofNumbers productOfNumbers;

    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2); 
    productOfNumbers.add(5);
    productOfNumbers.add(4);

    cout << productOfNumbers.getProduct(2) << endl; 
    cout << productOfNumbers.getProduct(3) << endl;
    cout << productOfNumbers.getProduct(4) << endl; 

    return 0;
}