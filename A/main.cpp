#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T,P;

int main(){
    cin >> N >> M >> P;

    int count = 0;
    for(int i = M; i <= N; i += P){
        count ++;
    }

    cout << count << endl;
    return 0;
}