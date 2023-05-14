
#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    //配列の取得
    //1次元
    vector<int> A(N);
    for(auto & a : A) cin >> a;

    bool check = true;

    for(int i = 0; i < A.size() - 1; i ++){
        int sub = abs(A[i + 1] - A[i]);
        if(sub != 1){
            if(A[i] < A[i + 1]){
                for(int j = 0; j < sub - 1; j ++){
                    A.insert(A.begin() + i + j + 1,A[i + j] + 1);
                }
            }
            else{
                for(int j = 0; j < sub - 1; j ++){
                    A.insert(A.begin() + i + j + 1,A[i + j] - 1);
                }
            }
        }
    }

    for(auto a : A) cout << a << " ";
    cout << endl;
    return 0;
}