#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    long long N, M, D;
    cin >> N >> M >> D;

    set<long long> A,B;
    for(int i = 0; i < N; i ++){
        long long a;
        cin >> a;
        A.insert(a);
    }
    for(int i = 0; i < M; i ++){
        long long b;
        cin >> b;
        B.insert(b);
    }

    while(A.size() != 0 && B.size() != 0){
        long long a_max = *A.rbegin();
        long long b_max = *B.rbegin();
        long long sub = abs(a_max - b_max);

        if(sub <= D){
            cout << a_max + b_max << endl;
            return 0;
        }
        else{
            if(a_max > b_max){
                A.erase(a_max);
            }
            else{
                B.erase(b_max);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}