#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int H,W;
    cin >> H >> W;

    vector<string> S(H);
    for(auto & s : S) cin >> s;

    for(int h = 0; h < H; h ++){
        for(int w = 0; w < W; w ++){
            if(S[h][w] == 's'){
                for(int i = -1; i <= 1; i ++){
                    for(int j = -1; j <= 1; j ++){
                        if(i == 0 && j == 0) continue;
                        if((h + i * 4) < 0 || H <= (h + i * 4)) continue;
                        if((w + j * 4) < 0 || W <= (w + j * 4)) continue;

                        if(S[h + i][w + j] != 'n') continue;
                        if(S[h + (i * 2)][w + (j * 2)] != 'u') continue;
                        if(S[h + (i * 3)][w + (j * 3)] != 'k') continue;
                        if(S[h + (i * 4)][w + (j * 4)] != 'e') continue;

                        for(int k = 0; k < 5; k ++){
                            cout << (h + 1) + (i * k) << " " <<  (w + 1) + (j * k) << endl; 
                        }

                        return 0;
                    }
                }

            }
        }
    }
    return 0;
}