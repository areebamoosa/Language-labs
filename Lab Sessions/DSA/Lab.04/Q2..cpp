// Backspace String Compare

#include<iostream>
using namespace std;

void pop(string &s){

    if (s == "") return;

    s = s.substr(0, s.size()-1);
}

bool backspaceCompare(string s, string t){
    string a = "", b = "";

    for (int i =0; i < s.size(); i++){
        if (s[i] == '#'){
            pop(a);
        } else{
            a += s[i];
        }
    }

    for (int i =0; i < t.size(); i++){
        if (t[i] == '#'){
            pop(b);
        } else{
            b += t[i];
        }
    }

    return a == b;
}

int main(){

    string s = "ab#c", t = "ad#c";
    cout << (backspaceCompare(s, t) ? "true" : "false");

    return 0;
}