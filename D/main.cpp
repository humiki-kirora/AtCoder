#include <bits/stdc++.h>
using namespace std;

int H,W;
const string snuke = "snuke";
bool check_move(vector<string> &S, int current_num,int i, int j,int pattern,vector<pair<int,int>> &pairs){
    if(i == H - 1 && j == W - 1) return true;
    for(int k = 0; k < pairs.size(); k ++){
        if(pairs[k].first == i && pairs[k].second == j) return false;
    }
    pairs.push_back(pair<int,int>(i,j));

    bool check = false;
    int next_num = current_num + 1;
    if(next_num == snuke.size()) next_num = 0;
    char next_char = snuke[next_num];
    cout << next_char << " " << i << " " << j << endl;

    if(0 <= i - 1 && pattern != 1){
        if(next_char == S[i - 1][j]){
            if(check_move(S,next_num,i - 1,j,3,pairs)) return true;
        }
    }

    if(i + 1 < H && pattern != 3){
        if(next_char == S[i + 1][j]){
            if(check_move(S,next_num,i + 1,j,1,pairs)) return true;
        }
    }

    if(0 <= j - 1 && pattern != 4){
        if(next_char == S[i][j - 1]){
            if(check_move(S,next_num,i,j - 1,2,pairs)) return true;
        }
    }

    if(j + 1 < W && pattern != 2){
        if(next_char == S[i][j + 1]){
            if(check_move(S,next_num,i,j + 1,4,pairs)) return true;
        }
    }

    return false;
}

int main(){
    cin >> H >> W;

    vector<string> S(H);
    for(auto & s : S) cin >> s;

    if(S[0][0] != 's'){
        cout << "No" << endl;
        return 0;
    }
    else{
        vector<pair<int,int>> pairs;
        if(check_move(S,0,0,0,0,pairs)){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }

    return 0;
}