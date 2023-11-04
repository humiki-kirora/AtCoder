#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;
    vector<ULLong> A(N);
    for(int i = 0; i < N; i ++) cin >> A[i];

    sort(A.begin(),A.end());

    ULLong ans = 0;
    for(int i = 0; i < N - ans; i ++){
        ULLong sum = 0;
        ULLong start = A[i];
        ULLong current = A[i];
        ULLong end = A[i] + M;

        
        int itr = distance(A.begin(),lower_bound(A.begin(),A.end(),end));
        if(ans < itr - i){
            ans = itr - i;
        }
    }

    cout << ans << endl;

    return 0;
}