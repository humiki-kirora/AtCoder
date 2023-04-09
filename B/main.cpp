#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K,Q;
    cin >> N >> K;
    vector<vector<int>> A(N,vector<int>(N,0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    cin >> Q;

    for(int i = 0; i < Q; i ++){
        int s,t;
        cin >> s >> t;
    }





    return 0;
}