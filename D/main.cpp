#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &a : A) cin >> a;

    int Q;
    cin >> Q;
    vector<pair<int,int>> times(Q);
    for(auto & t : times) cin >> t.first >> t.second;

    vector<int> cumsum(N,0);
    for(int i = 1; i < N; i += 2){
        cumsum[i] = cumsum[i - 1];
        cumsum[(i + 1)] = cumsum[i] + (A[(i + 1)] - A[i]);
    }

    // auto f{[&A, &cumsum](auto x) -> unsigned {
    //     const auto j = upper_bound(begin(A) + 1, end(A), x) - begin(A) - 1;
    //     return cumsum[j] + (cumsum[j + 1] - cumsum[j]) / (A[j + 1] - A[j]) * (x - A[j]);
    // }};

    for(auto & q : times){
        int l = q.first;
        int r = q.second;

        int start_index = distance(A.begin(), upper_bound(A.begin(),A.end(),l));
        int end_index = distance(A.begin(), lower_bound(A.begin(),A.end(),r));
        int ans = cumsum[end_index] - cumsum[start_index - 1];
 
        if(start_index % 2 == 0){
            ans -= l - A[start_index - 1];
        }
 
        if(end_index % 2 == 0){
            ans -= A[end_index] - r;
        }

        // int ans = f(r) - f(l);

        cout << ans << endl;
    }

    return 0;
}