#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

ULLong N,M,Q,K,T,D,P;

int main(){
    cin >> N >> D >> P;
    vector<int> F(N,0);
    for(int i = 0; i < N; i++) cin >> F[i];

    sort(F.begin(),F.end(),[](const int & a,const int & b){return a > b;});
    ULLong ans = 0;

    for(int i = 0; i < N; i += D){
        ULLong sum = 0;
        for(int j = i; j < i + D; j ++){
            if(j >= N) break;
            sum += F[j];
        }

        if(sum > P){
            ans += P;
        }
        else{
            ans += sum;
        }
    }

    cout << ans << endl;
    return 0;
}