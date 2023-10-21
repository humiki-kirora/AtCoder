#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

ULLong N,M,Q,K,T;

int main(){
    cin >> N;

    while(N % 3 == 0){
        N /= 3;
    }

    while(N % 2 == 0){
        N /= 2;
    }

    if(N != 1){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;

    return 0;
}