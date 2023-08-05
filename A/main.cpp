#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    if(S == "ACE" ||
       S == "BDF" ||
       S == "CEG" ||
       S == "DFA" ||
       S == "EGB" ||
       S == "FAC" ||
       S == "GBD"){
        cout << "Yes" << endl;
        return 0;
    }


    cout << "No" << endl;
    return 0;
}