#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;



int main(){
    cin >> N;

    int K,P;
    cin >> K >> P;
    vector<vector<ULLong>> A(N,vector<ULLong>(K + 1));

    for(int i = 0; i < N; i ++){
        for(int j = 0; j <= K; j ++){
            cin >> A[i][j];
        }
    }

    return 0;
}