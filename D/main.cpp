#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> Cs(H);
    for(int i = 0; i < H; i ++) cin >> Cs[i];

    vector<vector<pair<char,bool>>> C(H,vector<pair<char,bool>>(W));
    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            C[i][j].first = Cs[i][j];
            C[i][j].second = true;
        }
    }

    while(true){
        bool check = false;
        for(int i = 0; i < H; i ++){
            if(count(C[i].begin(),C[i].end(),[](const pair<char,bool> a){return a.second;}) < 2){
                continue;
            }

            for(int j = 0; j < W; j ++){
                
            }
        }
    }
}