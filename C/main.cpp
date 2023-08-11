#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for(auto & a : A) {cin >> a; sum += a;}

    long long mod = sum % N;
    long long divs = sum / N;
    
    sort(A.begin(),A.end());
    long long ans = 0;
    for(int i = 0; i < N - mod; i ++){ans += abs(A[i] - divs);}
    for(int i = N - mod; i < N; i ++){ans += abs(A[i] - (divs + 1));}
    
    cout << ans / 2 << endl;
    
    
    return 0;
}
