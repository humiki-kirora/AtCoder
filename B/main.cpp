#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    ULLong B;
    cin >> B;

    ULLong A = 1;
    ULLong prev = 1;
    while(true){
        auto ans = powf64x(A,A);
        if(ans == B){
            cout << A << endl;
            return 0;
        }

        if(ans > B || prev > ans) break;

        A ++;
        prev = ans;
    }

    cout << -1 << endl;
    return 0;
}