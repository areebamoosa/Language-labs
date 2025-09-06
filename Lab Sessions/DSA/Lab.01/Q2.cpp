// Write a program to calculate the GPA of students of all subjects in a single semester. Assume all the courses have the same credit hours (let's assume 3 credit hours)

#include <iostream>
using namespace std;

int main(){

    string names[5] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};

    float marks[5][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, 0},
        {4.0, 3.66, 2.66, 0, 0},
        {2.66, 2.33, 4.0, 0, 0},
        {3.33, 3.66, 4.0, 3.0, 3.33}};

    for (int i = 0; i < 5; i++){

        float sum = 0;
        int count = 0;
        float GPA;

        for (int j = 0; j < 5; j++){
            sum += marks[i][j];
            if (marks[i][j] != 0){  
            count++;
            }
        }
        GPA = sum / count;
        cout << names[i]<< " GPA = " << GPA << endl;
    }

    return 0;
}