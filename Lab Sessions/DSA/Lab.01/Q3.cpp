// Finding Middle Value in a sorted vector

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder{
public:
    vector<int> medianEl;

    MedianFinder() {}

    void addNum(int num){

        medianEl.push_back(num);

        sort(medianEl.begin(), medianEl.end());
    }

    double findMedian(){

        if (medianEl.size() % 2 != 0){

            return medianEl[medianEl.size() / 2];

        }

        return (medianEl[medianEl.size() / 2] + medianEl[(medianEl.size() / 2) - 1]) / 2.0;
    }
};

int main()
{
    MedianFinder mf;

    mf.addNum(5);
    mf.addNum(8);
    mf.addNum(4);
    mf.addNum(3);
    mf.addNum(1);
    mf.addNum(6);
    mf.addNum(10);

    double median = mf.findMedian();

    cout << "The median of this vector is : " << median << endl;

    return 0;
}