#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<int,int>> L(Q,pair<int,int>(0,0));
    for(int i = 0; i < Q ; i ++) {
        cin >> L[i].first >> L[i].second;
    }

    vector<int> cumsum(N + 1,0);

    for(int i = 1; i < N; i ++){
        cumsum[i + 1] = cumsum[i] + (S[i - 1] == S[i]);
    }

    for(int i = 0; i < Q; i ++){
        int l = L[i].first;
        int r = L[i].second;

        int ans = cumsum[r] - cumsum[l];
        cout << ans << endl;
    }

    return 0;
}