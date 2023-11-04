#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;

    for(int i = N; i <= 999; i ++){
        int ans = i % 10;
        int prod = (i / 100) * ((i / 10) % 10);
        if(ans == prod){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}