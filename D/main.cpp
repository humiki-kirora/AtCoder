#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<long long> X(N + 1);
    vector<long long> Y(N + 1);
    for(int i = 1; i <= N; i ++) cin >> X[i] >> Y[i];

    int ans = 0;
    vector<vector<long long>> dp(N + 1,vector<long long>(2,0));

    for(int i = 1; i < N + 1; i++){
        if(X[i] == 0){
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] + Y[i], dp[i - 1][0] + Y[i]));
            dp[i][1] = dp[i - 1][1];
        }
        else{
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + Y[i]);
        }
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}
