#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> M;

    string S1,S2,S3;
    cin >> S1 >> S2 >> S3;

    vector<bool> rell_1(10,false);
    vector<bool> rell_2(10,false);
    vector<bool> rell_3(10,false);

    for(int i = 0; i < M; i ++){
        rell_1[S1[i] - '0'] = true;
        rell_2[S2[i] - '0'] = true;
        rell_3[S3[i] - '0'] = true;
    }

    int min = M;

    for(int j = 0; j < 10; j ++){
        if(!(rell_1[j] && rell_2[j] && rell_3[j])) continue; 
        set<int> s1_p;
        set<int> s2_p;
        set<int> s3_p;

        for(int i = 0; i < M; i ++){
            if(!check[0] && (S1[i] - '0' == i)) {check[0] = true; continue;}
            if(!check[1] && (S2[i] - '0' == i)) {check[1] = true; continue;}
            if(!check[2] && (S3[i] - '0' == i)) {check[2] = true; continue;}
        }
    }

    cout << -1 << endl;
    return 0;
}