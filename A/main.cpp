#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T,X;

int main(){
    cin >> N >> X;
    vector<int> S(N,0);
    for(int i = 0; i < N; i ++) cin >> S[i];

    int sum = 0;
    for(auto s : S){
        if(X >= s){
            sum += s;
        }
    }

    cout << sum << endl;
    return 0;
}