#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> K;
    string S;
    cin >>S;

    S[K - 1] = S[K - 1] + 32;

    cout << S << endl;

    return 0;
}