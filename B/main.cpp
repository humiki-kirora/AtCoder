#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;

    vector<int> W(N);
    vector<int> X(N);

    for(int i = 0; i < N; i ++) cin >> W[i] >> X[i];

    vector<ULLong> sum(24,0);

    for(int i = 0; i < N; i ++){
        int persons = W[i];
        int base_time = X[i];

        int start = (9 - base_time + 24) %  24;
        
        for(int j = 0; j < 9; j ++){
            int time = (start + j) % 24; 
            sum[time] += persons;
        }
    }

    // for(int i = 0; i < 24; i ++){
    //     cout << sum[i] << endl;
    // }

    auto max_ind = *max_element(sum.begin(),sum.end());

    cout << max_ind << endl;

    return 0;
}