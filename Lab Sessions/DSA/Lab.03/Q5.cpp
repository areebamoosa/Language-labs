// Q5

#include<iostream>
using namespace std;

class link{
    public:

    string urlLink;
    link* prev;
    link* next;

    link(string url){
        urlLink = url;
        prev = next = NULL;
    }
};

class browserHistory{

    public:

    link* url;

    browserHistory(string homepage){
        url = new link (homepage);
    }

    // Visting URL from current page
    void visit(string newUrl){

        if (url->next != NULL) {
        link* temp = url->next;
        while (temp != NULL) {
            link* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        url->next = NULL; 
    }
        link* Newurl = new link(newUrl);
        url->next = Newurl;
        Newurl->prev = url;
        url = Newurl;
    }

    // Visiting prev page of history
    string back(int steps) {
        while (steps > 0 && url->prev != NULL) {
            url = url->prev;
            steps--;
            }
        return url->urlLink;
   }

   // Visiting forward url
    string forward(int steps) {
      while (steps > 0 && url->next != NULL) {
            url = url->next;
            steps--;
        }
        return url->urlLink;
    }
};

int main (){

    browserHistory bh("leetcode.com");
    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");
    cout << bh.back(1) << endl;
    cout << bh.back(1) << endl;
    cout << bh.forward(1) << endl;
    bh.visit("linkedin.com");
    cout << bh.forward(2) << endl;    
    cout << bh.back(2) << endl;       
    cout << bh.back(7) << endl;       

    return 0;
}