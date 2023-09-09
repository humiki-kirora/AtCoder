#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

long double N,M,Q,K,T;

int main(){
    cin >> N >> K;
    long double ans = 0;

    for(int i = 1; i <= N; i ++){
        int count = 0;
        int tmp_num = i;
        while(true){
            if(K <= tmp_num) break;
            tmp_num *= 2;
            count ++;
        }

        if(count == 0){
            ans += (N - (i - 1)) / N; 
            break;
        }

        ans += pow(0.5,count) * (1.0 / N);
    }

    cout << setprecision(12) << ans << endl;
    return 0;
}