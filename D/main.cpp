#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    string R,C;
    cin >> R >> C;

    vector<vector<char>> map(N,vector<char>(N,'.'));
    for(int i = 0; i < N; i ++){
        map[i][0] = R[i];
    }

    for(int i = 0; i < N; i ++){
        map[0][i] = C[i];
    }

    return 0;
}