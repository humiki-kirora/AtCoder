#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<int> A(N * 7);
    for(auto & a : A) cin >> a;

    vector<int> sums;
    for(int i = 0; i < N * 7; i += 7){
        int sum = 0;
        for(int j = 0; j < 7; j ++) {sum += A[i + j];}
        sums.push_back(sum);
    }

    for(int i = 0; i < sums.size() - 1; i ++){
        cout << sums[i] << " ";
    }
    cout << sums[sums.size() - 1] << endl;

    return 0;
}