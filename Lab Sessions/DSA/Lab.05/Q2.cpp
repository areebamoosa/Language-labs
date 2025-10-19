// Showing winner of a game

#include<iostream>
using namespace std;

class Winner{
    int *friends;
    int size;
    int front;
    int rear;

    public:

    Winner(int n){
        size = n;
        friends = new int[size];
        front = rear = -1;
    }

    void addMember(int x){
        if (isFull()){
            cout << "The Members of the game are full." << endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
            friends[rear] = x;
            return;
        }
        rear = (rear + 1 ) % size;
        friends[rear] = x;
    }

    void remMember(){
        if (isEmpty()){
            cout << "There are no members left to remove" << endl;
            return;
        }
        if ( front == rear){
            front = rear = -1;
            return;
        }
        front = (front + 1) % size;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return front == (rear + 1) % size;
    }

    int getFront(){
        return friends[front];
    }

    // Counting members in the game
    int countMembers(){
        if (isEmpty()){
            return 0;
        } else if ( rear >= front){
            return rear - front + 1;
        } else{
            return size - front + rear + 1;
        }
    }

    // Game Logic Function
    int gameWinner(int k){
        while (countMembers() > 1){
            // Rotating the queue
            for (int i =0; i < k-1; i++){
                int temp = getFront();
                remMember();
                addMember(temp);
            }
            // Removing Members
            cout << "Eliminated: " << getFront() << endl;
            remMember();

        }
        // Returning the last member that is left who is thee winner
        return getFront();
    }

};

int main(){

    Winner w(5);

    w.addMember(1);
    w.addMember(2);
    w.addMember(3);
    w.addMember(4);
    w.addMember(5);

    int winner = w.gameWinner(3);
    cout << "Winner: " << winner;

    return 0;
}