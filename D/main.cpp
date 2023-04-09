#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B;
    cin >> A >> B;

    long long count = 0;
    //馬鹿正直にやるとTLE
    // while(A != B){
    //     bool C = (A > B);
    //     A -= B * C;
    //     B -= A * !C;
    //     count ++;
    // }

    //ちょっと工夫
    //A > Bの時に A <= Bになるまで(A - B)を行う回数はA / B,終わった後のAの値はA mod B
    //したがって,最初にA,Bの大小関係を確認して、L = max(A,B) R = min(A,B)として、
    //回数にL / Rを加算、L = R, R = L mod Rを行う事で繰り返し回数を削減できる
    long long L,R;
    long long mod;
    if(A > B){L = A; R = B;}
    else {L = B; R = A;}

    mod = L % R;

    while(mod != 0){
        count += L / R;

        L = R;
        R = mod;
        mod = L % R;
    }

    count += (L / R) - 1;

    cout << count << endl;

    return 0;
}