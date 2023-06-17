#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<int> A(3 * N);
    for(auto & a : A) cin >> a;

    vector<int> ans(N,0);
    int count = 0;

    vector<int> check(N,0);
    for(int i = 0; i < 3 * N; i ++){
        if(check[A[i] - 1] == 0){
            check[A[i] - 1] ++;
        }
        else if(check[A[i] - 1] == 1){
            ans[count] = A[i];
            check[A[i] - 1]++;
            count ++;
        }

        if(count == N){
            break;
        }
    }

    for(int i = 0; i < N - 1; i ++){
        cout << ans[i] << " ";
    }
    cout << ans[N - 1] << endl;

    return 0;
}