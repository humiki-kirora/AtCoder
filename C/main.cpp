#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int gcd(int a,int b){
    if(b == 0) return a;

    return gcd(b , a % b);
}

int main(){
    ULLong A,B;
    cin >> A >> B;

    int g = gcd(A,B);
    ULLong ans = A / g * B;
    cout << ans << endl;

    return 0;
}