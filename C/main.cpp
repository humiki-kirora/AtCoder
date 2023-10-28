#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i ++) cin >> S[i];

    vector<vector<int>> p_dst(H,vector<int>(W,0));
    vector<int> lookup(1000 * 1000,0);
    int current_table = 1;
    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            if(S[i][j] == '#'){
                ULLong min = INT32_MAX;
                if(0 <= i - 1){
                    
                    if(0 <= j - 1){
                        if(S[i - 1][j - 1] == '#' && p_dst[i - 1][j - 1] < min) min =  p_dst[i - 1][j - 1];
                    }

                    if(S[i - 1][j] == '#' && p_dst[i - 1][j] < min) min =  p_dst[i - 1][j];
                    
                    if(j + 1 < W){
                        if(S[i - 1][j + 1] == '#' && p_dst[i - 1][j + 1] < min) min =  p_dst[i - 1][j + 1];
                    }
                }
                if(0 <= j - 1){
                    if(S[i][j - 1] == '#' && p_dst[i][j - 1] < min) min =  p_dst[i][j - 1];
                }

                if(min == INT32_MAX){
                    p_dst[i][j] = current_table;
                    lookup[current_table] = current_table;
                    current_table ++;
                }
                else{
                    p_dst[i][j] = min;
                    if(0 <= i - 1){
                        if(0 <= j - 1){
                            lookup[p_dst[i - 1][j - 1]] = min;
                        }
                        lookup[p_dst[i - 1][j]] = min;
                        if(j + 1 < W){
                            lookup[p_dst[i - 1][j + 1]] = min;
                        }
                    }
                    if(0 <= j - 1){
                        lookup[p_dst[i][j - 1]] = min;
                    }
                }
            }
            else{
                p_dst[i][j] = 0;
            }
            
        }
    }

    // for(int i = 0; i < H; i ++){
    //     for(int j = 0; j < W; j ++){
    //         if(p_dst[i][j] != 0){
    //             p_dst[i][j] = lookup[p_dst[i][j]];
    //         }
    //     }
    // }

    // for(int i = 0; i < H; i ++){
    //     for(int j = 0; j < W-1; j ++){
    //         cout << p_dst[i][j];
    //     }
    //     cout << p_dst[i].back() << endl;
    // }


    set<int> num;
    for(int i = 1; 0 != lookup[i]; i ++){
        num.insert(lookup[i]);
    }

    cout << num.size() << endl;

    return 0;
}