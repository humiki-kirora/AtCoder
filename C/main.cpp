/*ポイント：vectorのfindはO(N)となりO(N^2)かかるが、
            setのfindはsort済みなので二分探索でO(logN)で計算可能。よって0(NlogN)で計算可能*/
/*線形ソートしてから、尺取法で探索してもO(N)に落とし込める*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;
    X = abs(X);

    if(X == 0) {cout << "Yes" << endl; return 0;}

    set<int> A;
    for(int i = 0; i < N; i ++){
        int t;
        cin >> t;
        A.insert(t);
    }

    for(auto a : A){
        if(A.find(a + X) != A.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}