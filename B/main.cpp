#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    vector<unsigned long long> A(64);

    for(auto & a : A) cin >> a;
    unsigned long long ans = 0;
    for(int i = 0; i < A.size(); i ++){
        ans += A[i] * (A[i] << i);
    }

    cout << ans << endl;

    return 0;
}