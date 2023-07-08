#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<long long> A(N);
    vector<long long> B(N);
    for(int i = 0; i < N; i ++) cin >> A[i] >> B[i];

    vector<vector<double>> p(N,vector<double>(2,0));
    for(int i = 0; i < N; i ++){
        p[i][0] = i + 1;
        p[i][1] = (double)A[i] / (double)(A[i] + B[i]);
    }

    stable_sort(p.begin(),p.end(),[](const vector<double> &a, const vector<double> &b){return a[1] > b[1];});

    for(int i = 0; i < N - 1; i ++) cout << (int)p[i][0] << " ";
    cout << (int)p[N - 1][0] << endl;

    return 0;
}