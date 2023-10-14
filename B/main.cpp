#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;
    string S,T;
    cin >> S >> T;

    bool first = true;
    bool end = true;

    for(int i = 0; i < N; i ++){
        if(S[i] != T[i]){
            first = false;
        }
    }

    for(int i = M - 1, j = N - 1; j >= 0; j --, i --){
        if(S[j] != T[i]){
            end = false;
        }
    }

    if(first){
        if(end){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    else{
        if(end){
            cout << 2 << endl;
        }
        else{
            cout << 3 << endl;
        }
    }
    return 0;
}