#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    vector<int> a(N + 1,0);
    for(int i = 1; i <= N;  i ++) cin >> a[i];

    stack<int> s;
    int current = 1;
    for(int i = 1; i <= N; i ++){
        if(current == a[i]){
            s.push(current);
            current ++;
        }
    }

    if(s.size() == 0) cout << -1 << endl;
    else{
        cout << N - s.size() << endl;
    }

    return 0;
}