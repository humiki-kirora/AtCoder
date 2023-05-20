#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    long long A,B;
    cin >> A >> B;

    long long a = (A / B);
    long long b = A % B == 0 ? 0 : 1;

    cout << a + b << endl; 
    return 0;
}