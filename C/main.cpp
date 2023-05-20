#include <bits/stdc++.h>
using namespace std;
 
bool check_change(string s1, string s2){
    int count = 0;
    for(int i = 0; i < s1.size(); i ++){
        if (s1[i] != s2[i]) count ++;
    }
    return count < 2;
}

int main(){
    //回数の取得
    int N,M;
    cin >> N >> M;

    vector<string> S(N);
    for(auto & s : S) cin >> s;

    vector<vector<bool>> check_matrix(N,vector<bool>(N,false));
    for(int i = 0; i < N; i ++){
        for(int j = i + 1; j < N; j ++){
            check_matrix[i][j] = check_matrix[j][i] = check_change(S[i],S[j]);
        }
    }

    set<int> group;
    group.insert(0);
    vector<bool> checks(N,false);
    bool check_update = true;
    while(check_update){
        check_update = false;
        for(auto g : group){
            if(checks[g]) continue;
            for(int i = 0; i < N; i ++){
                if(check_matrix[g][i]){group.insert(i); check_update = true;}
            }
            checks[g] = true;
        }
    }

    if(group.size() == N){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}