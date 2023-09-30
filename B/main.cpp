#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T,X;

int main(){
    cin >> N >> X;

    vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i ++) cin >> A[i];

    sort(A.begin(),A.end());

    int sum = 0;
    int mins = A[0];
    int maxs = A[N - 1]; 
    for(int i = 1; i < N - 2; i ++){
        sum += A[i];
    }

    if(X - sum > 100){
        cout << -1 << endl;
    }
    else{
        int sub = X - sum;
        if(sub > A.back()){
            cout << -1 << endl;
        }
        else{
            if(sub > A.front()){
                cout << sub << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}