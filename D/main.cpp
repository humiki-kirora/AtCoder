#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    vector<vector<int>> cost(N + 1);
    for(int i = 1; i <= N - 1; i ++){
        for(int j = i + 1; j <= N; j ++){
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }

    

    return 0;
}