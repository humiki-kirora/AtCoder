#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    int tmp = N % 5 > 2 ? 5 - (N  % 5) : N % 5 * -1;
    int ans = N + tmp;

    cout << ans << endl;

    return 0;
}