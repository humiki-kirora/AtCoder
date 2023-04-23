#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    int fs = S.find("|");
    int es = S.rfind("|");

    int ts = S.find("*");

    if(fs < ts && ts < es){
        cout << "in" << endl;
        return 0;
    }
    
    cout << "out" << endl;

    return 0;
}