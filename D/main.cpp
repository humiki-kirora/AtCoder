
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    
    int N;
    cin >> N;
    
    int range = 0;
    int tmp_N = N;
    string N_to = "";
    while(true){
        char mod = (tmp_N % 2);
        N_to.insert(N_to.begin(),(char)mod);
        range ++;
        tmp_N = tmp_N / 2;
        if(tmp_N == 0) break;
    }

    if(range > S.size()){

    }

    for(int i = S.size() - range - 1; i >= 0; i --){
        if(S[i] == '?') {S[i] = 0; continue;}
        if(S[i] == '1') {cout << -1 << endl; return 0;}
    }

    string substr = S.substr(S.size() - range - 1,range);
    auto current_itr = N_to.begin();
    int count_q = count(substr.begin(),substr.end(),'?');



    return 0;
}