#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    string S,T;
    cin >> S >> T;
    cout << S;

    for(int i = 0; i < S.size(); i ++){
        if(S[i] != T[i]){
            if((S[i] == '1' || S[i] == 'l') && (T[i] == '1' || T[i] == 'l')) continue;
            if((S[i] == '0' || S[i] == 'o') && (T[i] == '0' || T[i] == 'o')) continue;

            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}