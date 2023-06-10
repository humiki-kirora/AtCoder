#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    long long N;
    cin >> N;

    if(N <= 1e+3 - 1){
        cout << N << endl;
    }
    else if(N  <= 1e+4 - 1){
        N -= N % 10;
        cout << N << endl;
    }
    else if(N  <= 1e+5 - 1){
        N -= N % 100;
        cout << N << endl;
    }
    else if(N  <= 1e+6 - 1){
        N -= N % 1000;
        cout << N << endl;
    }
    else if(N  <= 1e+7 - 1){
        N -= N % 10000;
        cout << N << endl;
    }
    else if(N  <= 1e+8 - 1){
        N -= N % 100000;
        cout << N << endl;
    }
    else if(N  <= 1e+9 - 1){
        N -= N % 1000000;
        cout << N << endl;
    }

    return 0;
}