#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    string S;
    cin >> S;

    for(int i = 0; i < S.size() - 1; i ++){
        cout << S[i] << " ";
    }
    cout << S.back() << endl;
    return 0;
}