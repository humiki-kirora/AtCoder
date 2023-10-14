#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;



int main(){

    vector<vector<string>> poly(3,vector<string>(4));
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 4; j ++) cin >> poly[i][j];
    }

    bool map[4][4];
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 4; j ++) cin >> poly[i][j];
    }


    return 0;
}