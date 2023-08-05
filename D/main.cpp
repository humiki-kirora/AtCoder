#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    stack<int> l_st;
    stack<int> r_st;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '(') l_st.push(i);
        if(S[i] == ')') r_st.push(i);
    }



    cout << "Yes" << endl;
    return 0;
}