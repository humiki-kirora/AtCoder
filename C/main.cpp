#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<long long> A(N);
    vector<long long> B(M);

    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i = 0; i < A.size(); i++){
        int sold = i + 1;
        int itr_b = distance(B.begin(),upper_bound(B.begin(),B.end(),A[i]));
        int buy = B.size() - itr_b;
        if(sold >= buy){
            if(itr_b < B.size()){
                cout << A[i] << endl;
                return 0;
            }
            else{
                if(B.back() < A[i]){
                    cout << B.back() + 1 << endl;
                    return 0;
                }
                else{
                    cout << A[i]<< endl;
                    return 0;
                }
            }
        }
        
    }
    return 0;
}