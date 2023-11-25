#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;
    vector<int> A(M,0);
    for(int i = 0; i < M; i ++) cin >> A[i];

    int current = 0;
    int current_max = 0;
    vector<int> current_state(N,0);

    for(int i = 0; i < M; i ++){
        current_state[A[i] - 1] ++;
        if(current_max < current_state[A[i] - 1]){
            current = A[i] - 1;
            current_max = current_state[A[i] - 1];
        }
        else if (current_max == current_state[A[i] - 1]){
            current = min(current,A[i] - 1);
        }

        cout << current + 1 << endl;
    }
    
    return 0;
}