#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    bool check = true;
    char prev_sex = S[0];

    for(int i = 1; i < N; i++){
        if(prev_sex == S[i]){
            check = false;
            break;
        }
        prev_sex = S[i];
    }

    if(check){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;;
    }

    return 0;
}