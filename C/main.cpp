#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int H,W;
    cin >> H >> W;

    vector<vector<char>> S(H,vector<char>(W,0));

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> S[i][j];
        }
    }

    int start_x = 0;
    int start_y = 0;
    int end_x = 0;
    int end_y = 0;
    for(int i = 0; i < H; i ++){
        auto itr = find(S[i].begin(),S[i].end(),'#'); 
        if(itr != S[i].end()){
            start_x = distance(S[i].begin(),itr);
            end_x = W - distance(S[i].rbegin(),find(S[i].rbegin(),S[i].rend(),'#'));
            start_y = i;
            break;
        }
    }


    for(int i = H - 1; i >= 0; i --){
        auto itr = find(S[i].rbegin(),S[i].rend(),'#'); 
        if(itr != S[i].rend()){
            int tmp_s = distance(S[i].begin(),find(S[i].begin(),S[i].end(),'#'));
            start_x = start_x < tmp_s ? start_x : tmp_s;

            int tmp_e = W - distance(S[i].rbegin(),itr);
            end_x = end_x > tmp_e ? end_x : tmp_e;
            end_y = i + 1;
            break;
        }
    }

    for(int i = start_y; i < end_y; i ++){
        for(int j = start_x; j < end_x; j ++){
            if(S[i][j] == '.'){
                cout << i + 1 << " " << j + 1 << endl;;
                return 0;
            }
        }
    }
    
    return 0;
}