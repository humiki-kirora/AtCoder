#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    string S;
    cin >> S;

    for(int i = 0; i < N; i ++){
        if(S[i] == 'A'){
            if(S[i + 1] == 'B' && S[i + 2] == 'C'){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}