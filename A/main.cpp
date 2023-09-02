#include <bits/stdc++.h>
using namespace std;

int N,M,H,W,Q,K,T,X;

int main(){
    cin >> N >> H >> X;
    vector<int> P(N + 1);
    for(int i = 1; i <= N; i ++) cin >> P[i];

    for(int i = 1; i <= N; i ++){
        if(H + P[i] >= X){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}