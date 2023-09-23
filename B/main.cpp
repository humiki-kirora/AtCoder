#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    string S;
    cin >> S;

    vector<vector<bool>> dp(S.size(),vector<bool>(S.size(),false));
    int max_len = 1;
    for(int i = 0; i < S.size(); i ++){
        dp[i][i] = true;
    }

    for(int i = 0; i < S.size() - 1; i ++){
        dp[i][i+1] = S[i] == S[i + 1] ? true : false;
        if(dp[i][i+1]) max_len = 2;
    }

    for(int len = 2; len < S.size(); len ++){
        for(int i = 0; i < S.size() - len; i ++){
            int r = i + len;
            if(S[i] == S[r] && dp[i + 1][r - 1]){
                dp[i][r] = true;
                max_len = len + 1;
            } 
        }
    }

    cout << max_len << endl;

    return 0;
}