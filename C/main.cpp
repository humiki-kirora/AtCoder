#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

ulong D,N,M,Q,K,T;

int main(){
    cin  >> N;

    vector<ulong> A(N,0);
    vector<ulong> sortA(N,0);
    for(int i = 0; i < N; i ++) {
        cin >> A[i];
        sortA[i] = A[i];
    }
    sort(sortA.begin(),sortA.end());
    vector<ulong> cumsum(N + 1,0);

    cumsum[0] = 0;
    for(int i = 0; i < N; i ++){
        cumsum[i + 1] = sortA[i] + cumsum[i];
    }

    for(int i = 0; i < N - 1; i ++){
        int dist = distance(sortA.begin(),upper_bound(sortA.begin(),sortA.end(),A[i]));
        cout << cumsum[N] - cumsum[dist] << " ";
    }

    int dist = distance(sortA.begin(),upper_bound(sortA.begin(),sortA.end(),A.back()));
    cout << cumsum[N] - cumsum[dist] << endl;
    return 0;
}