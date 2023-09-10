#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;
    vector<ULLong> L(N+1,0);
    for(int i = 1; i <= N; i++) cin >> L[i];

    vector<ULLong> cumsum(N + 1,0);
    cumsum[0] = 0;
    cumsum[1] = L[1];

    for(int i = 2; i <= N; i++){
        cumsum[i] = cumsum[i - 1] + L[i];
    }

    ULLong min_w = ULLONG_MAX;

    for(int i = 1; i <= N; i ++){
        for(int j = i; j <= N; j ++){
            ULLong width = cumsum[j] - cumsum[i - 1] + (j - i);
            
            if(min_w < width) break;
            if(cumsum[N] / width >= M) continue;

            int back_M = 1;
            if(i == 1) back_M = 0;
            else{
                back_M = (cumsum[i - 1] - cumsum[0] + (i  - 1)) / width + 1;
            }

            int front_M;
            if(j == N) front_M = 0;
            else{
                front_M = (cumsum[N] - cumsum[j] + (N - j - 1)) / width + 1;
            }

            ULLong all_M = 1 + back_M + front_M;
            if(all_M == M && min_w > width){
                min_w = width;
            }
        }
    }

    cout << min_w << endl;

    return 0;
}