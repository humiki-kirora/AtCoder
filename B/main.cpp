/*Clear 2023/04/09*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    //condition1
    auto f_b = S.find("B");
    auto s_b = S.rfind("B");

    if((f_b % 2) == (s_b % 2)) {cout << "No" << endl; return 0;}
    
    //condition2
    auto f_r = S.find("R");
    auto s_r = S.rfind("R");
    auto k = S.find("K");

    if(k < f_r || s_r < k) {cout << "No" << endl; return 0;}

    cout << "Yes" << endl;

    return 0;
}