#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;

    vector<int> A(M);

    for(int i = 0; i < M; i ++ ) cin >> A [i];

    int count = 0;
    for(int i = 0; i < N; i ++){
        cout << A[count] - (i + 1) << endl;
        if(A[count] - (i + 1) == 0){
            count ++;
        }
    }

    return 0;
}