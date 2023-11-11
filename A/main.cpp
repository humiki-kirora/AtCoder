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

    for(int i = 0; i < S.size() - 1; i ++){
        if(S[i] == 'a' && S[i + 1] == 'b'){
            cout << "Yes" << endl;
            return 0;
        }
        if(S[i] == 'b' && S[i + 1] == 'a'){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}