#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    if(S.find("o") == string::npos){ cout << "No" << endl; return 0;}

    if(S.find("x") != string::npos){ cout << "No" << endl; return 0;}

    cout << "Yes" << endl;

    return 0;
}