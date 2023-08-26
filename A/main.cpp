#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i ++){
        if(S[i] != 'a' &&
           S[i] != 'e' &&
           S[i] != 'i' &&
           S[i] != 'o' &&
           S[i] != 'u'){
            cout << S[i];
        }

    }

    cout << endl;


    return 0;
}
