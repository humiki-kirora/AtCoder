#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N, M;
    cin >> N >> M;

    vector<string> C(N);
    for(int i = 0; i < N; i ++) cin >> C[i];

    vector<string> D(M);
    for(int i = 0; i < M; i ++) cin >> D[i];

    vector<int> P(M + 1);
    for(int i = 0; i <= M; i ++) cin >> P[i];

    long long sum = 0;
    for(int i = 0; i < N; i ++){
        auto itr = find(D.begin(),D.end(),C[i]);
        if(itr != D.end()){
            int dist = distance(D.begin(),itr);
            sum += P[dist + 1];
        }
        else{
            sum += P[0];
        }
    }

    cout << sum << endl;

    return 0;
}