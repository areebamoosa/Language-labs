// Designing a simple customer service call center simulation.

#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

class Call{
    int id;
    int time;
    string name;

    public:

    Call(int i, int t, string n){
        id = i;
        time = t;
        name = n;
    }

    int getId() { return id; }
    int getTime() { return time; }
    string getName() { return name; }
};

class callCenter{
    int CSR;
    queue<Call> incomingCalls;
    vector<bool> availableCSRs;
 
    public:

    callCenter(int c){
        CSR = c;
        availableCSRs.resize(CSR, true);
    }

    // Adding a new call
    void add(Call c){
        incomingCalls.push(c);
    }

    // Processing all calls
    void processCalls() {

        cout << "\nProcessing calls...\n";
        while (!incomingCalls.empty()) {

            for (int i = 0; i < CSR; i++) {
                if (incomingCalls.empty()) break; 
                if (availableCSRs[i]) {
                    Call current = incomingCalls.front();
                    incomingCalls.pop();
                    availableCSRs[i] = false;

                    cout << "CSR : " << i + 1 << " is handling Call " << current.getId() << " from " << current.getName() << endl;

                    cout << "CSR : " << i + 1 << " finished the Call " << current.getId() << endl;

                    availableCSRs[i] = true;
                }
            }
        }
        cout << "\nAll calls have been processed!\n";
    }

};

int main(){
    callCenter center(3);

    center.add(Call(1, 5, "Areeba"));
    center.add(Call(2, 3, "Meerub"));
    center.add(Call(3, 4, "Ibrahim"));
    center.add(Call(4, 2, "Aryana"));

    center.processCalls();

    return 0;
}