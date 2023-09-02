#include <bits/stdc++.h>
using namespace std;

int N,M,H,W,Q,K,T;

int main(){
    cin >> N;

    vector<int> A(N + 1,0);
    for(int i = 1; i <= N; i ++) cin >> A[i];

    sort(A.begin(),A.end());
    for(int i = 2; i <= N; i ++){
        if(A[i] - A[i - 1] > 1){
            cout << A[i] - 1 << endl;
            return 0;
        }
    }

    return 0;
}