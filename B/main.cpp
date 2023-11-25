#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;

    vector<int> A(N,0);
    for(int i = 0; i < N; i ++) cin >> A[i];
    sort(A.begin(),A.end());
    int max = A.back();

    for(int i = N - 1; i >= 0; i--){
        if(A[i] != max){
            cout << A[i] << endl;
            return 0;
        }
    }

    return 0;
}