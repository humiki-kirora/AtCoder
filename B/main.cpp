#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(M,vector<int>(N,0));
    for(auto & av : A){
        for(auto & a : av) cin >> a; 
    }

    vector<vector<bool>> check(N,vector<bool>(N,false));

    for(auto & av : A){
        for(int i = 0; i < av.size() - 1; i ++){
            check[av[i] - 1][av[i + 1] - 1] = check[av[i + 1] - 1][av[i] - 1] = true;
        }
    }

    int count = 0;
    for(auto & c : check){
        for(int i = 0; i < c.size(); i ++){
            count += c[i];
        }
    }

    cout << ((N * N) - N - count) / 2 << endl;
    return 0; 
}