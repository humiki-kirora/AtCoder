#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    vector<char> S(N + 1);
    vector<int> divs;

    int tmp_N = N;
    for(int j = 1; j <= 9; j ++){
        if(N % j == 0) divs.push_back(j);
    }

    for(int i = 0; i <= N; i ++){
        bool check = false;
        for(int j = 0; j < divs.size(); j ++){
            if(i % (N / divs[j]) == 0) {
                S[i] = '0' + divs[j];
                check = true;
                break;
            }
        }

        if(!check) S[i] = '-';
    }

    for(int i = 0; i < N; i ++){
        cout << S[i];
    }
    cout << S[N] << endl;


    return 0;
}