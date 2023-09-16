#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    string S,T;
    cin >> S >> T;

    for(int i = 0; i < S.size() - 1; i ++){
        cout << S[i] << T[i];
    }
    cout << S[N - 1] << T[N - 1] << endl;

    return 0;
}