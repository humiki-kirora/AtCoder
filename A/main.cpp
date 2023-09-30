#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    int prev = N % 10;
    N /= 10;
    while(N != 0){
        int mod = N % 10;
        if(prev >= mod){
            cout << "No" << endl;
            return 0;
        }

        prev = mod;
        N /= 10;
    }

    cout << "Yes" << endl;
    return 0;
}