// Create a single class Sort, which will provide the user the option to choose between all 3
// sorting techniques. The class should have following capabilities:
// - Take an array and a string (indicating the user choice for sorting technique) as input and
// perform the desired sorting.
// - Should allow the user to perform analysis on a randomly generated array. The analysis
// provides number of comparisons and number of swaps performed for each technique.
// - After printing all the results in the main program, highlight the best and worst techniques.

#include<iostream>
#include <cstdlib>
#include <ctime>    
using namespace std;

class Sort{

    int *arr;
    int size;
    int comp;
    int swaps;
    string technique;

    public:

    Sort(int s, string t){
        size = s;
        arr = new int[size];
        comp = 0;
        swaps = 0;
        technique = t;
    }

    ~Sort(){
        delete[] arr;
    }

    // Copy array into object
    void setArray(int a[]) {
        for (int i = 0; i < size; i++)
            arr[i] = a[i];
    }

    // Function to choose sorting technique
    void sortTechnique(){
        if (technique == "bubble"){
            bubbleSort();
        }
        else if (technique == "selection"){
            selectionSort();
        }
        else if (technique == "insertion"){
            insertionSort();
        } else{
            cout << "Invalid sorting choice" << endl;
        }
    }
    // Print stats for analysis
    void printStats() {
        cout << "Technique: " << technique << endl;
        cout << "Comparisons: " << comp << endl;
        cout << "Swaps: " << swaps << endl;
    }

    int getComp() { return comp; }
    int getSwaps() { return swaps; }
    string getTechnique() { return technique; }

    private:

    void bubbleSort(){
        for (int i =0; i < size-1; i++){
            for (int j=0; j < size - i -1; j++){
             comp++;

                if (arr[j] > arr[j+1]){
                    swap(arr[j] , arr[j+1]);
                swaps++;
                }
            }
        }
    }

    void selectionSort(){
        for (int i =0; i<size-1; i++){
            int smallest = i;
            for (int j=i+1; j < size; j++){
                comp++;
                if (arr[j] < arr[smallest]){
                    smallest = j;
                }
            }
            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                swaps++;
            }
        }
    }

    void insertionSort(){
        for (int i = 1; i < size; i++){
            int curr = arr[i];
            int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
                comp++;
                arr[prev + 1] = arr[prev];
                swaps++;
                prev--;
            }
        if (prev >= 0) comp++; 
        arr[prev + 1] = curr;
        }
    }
};

int main(){

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Generating random array
    int *arr = new int[n];

    srand(time(0));
    // Without this, rand() would give the same numbers every time you run the program, so this is neccessary

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100; 

    cout << "\nRandom Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";

    // Sorting objects for each technique
    Sort bubble(n, "bubble");
    Sort selection(n, "selection");
    Sort insertion(n, "insertion");

    // Copy same random array into each
    bubble.setArray(arr);
    selection.setArray(arr);
    insertion.setArray(arr);

    // Sorting each
    bubble.sortTechnique();
    selection.sortTechnique();
    insertion.sortTechnique();

    // Printing Stats
    cout << "Sorting Analysis \n";
    bubble.printStats();
    selection.printStats();
    insertion.printStats();

    // Find best and worst case (based on comparisons)
    Sort *best = &bubble;
    Sort *worst = &bubble;

    Sort *methods[3] = {&bubble, &selection, &insertion};
    for (int i = 1; i < 3; i++) {
        if (methods[i]->getComp() < best->getComp())
            best = methods[i];
        if (methods[i]->getComp() > worst->getComp())
            worst = methods[i];
    }

    cout << "\nBest Technique: " << best->getTechnique() << " Sort";
    cout << "\nWorst Technique: " << worst->getTechnique() << " Sort\n";

    delete[] arr;

    return 0;
}
