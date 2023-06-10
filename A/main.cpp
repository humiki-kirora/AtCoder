#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<string> S(N);
    vector<long long> A(N);

    for(int i = 0; i < N; i ++){
        cin >> S[i] >> A[i];
    }

    auto min_index = min_element(A.begin(),A.end());
    int dist = distance(A.begin(),min_index);

    for(int  i = dist; i < N; i ++){
        cout << S[i] << endl;
    }
    for(int i = 0; i < dist; i ++){
        cout << S[i] << endl;
    }
    return 0;
}