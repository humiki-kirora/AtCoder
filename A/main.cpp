#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    vector<int> S(8);
    for(int i = 0; i < 8; i ++) cin >> S[i];

    bool check = true;
    int max = 0;

    for(int i = 0; i < 8; i ++){
        if(max > S[i]){
            check = false;
            break;
        }

        if(S[i] < 100 || 675 < S[i]){
            check = false;
            break;
        }

        if(S[i] % 25 != 0){
            check = false;
            break;
        }

        max = S[i];
    }

    if(check){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0;
}