#include <bits/stdc++.h>
using namespace std;


int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> C(N);
    for(int i = 0; i < N; i ++){
        cin >> C[i];
    }

    int ans = A + B;

    auto itr = find(C.begin(),C.end(),ans);
    
    cout << distance(C.begin(),itr) + 1 << endl;

    return 0;
}