#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    long long A,B;
    cin >> A >> B;
    cout << int(pow(A,B) + pow(B,A)) << endl;
    return 0;
}