#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<long long> A(N);
    vector<long long> current(N * 2);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long min = *min_element(A.begin(),A.end());

    for(int i = 0; i < N; i++){
        current[i] = A[i];
        current[i + N] = A[i] + min;
    }

    set<long long> price;
    while(price.size() != K){
        std::vector<long long>::iterator iter = min_element(current.begin(),current.end());
        long long index = std::distance(current.begin(),iter);
        price.insert(current[index]);
        current[index] += min;
    }

    cout << *max_element(price.begin(),price.end()) << endl;


    return 0;
}