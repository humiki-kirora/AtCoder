#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<pair<long,long>> FSs(N + 1);
    for(int i = 1; i <= N; i ++){
        cin >> FSs[i].first >> FSs[i].second;
    }

    struct ice{
        int f;
        int s;
        long long score;
    };

    vector<struct ice> dp(N+1);

    if(FSs[1].first == FSs[2].first){
        if(FSs[1].second > FSs[2].second){
            dp[2].f = 1;
            dp[2].s = 2;
            dp[2].score = FSs[1].second + FSs[2].second / 2;
        }
        else{
            dp[2].f = 2;
            dp[2].s = 1;
            dp[2].score = FSs[2].second + FSs[1].second / 2;
        }
    }
    else{
        if(FSs[1].second > FSs[2].second){
            dp[2].f = 1;
            dp[2].s = 2;
            dp[2].score = FSs[1].second + FSs[2].second;
        }
        else{
            dp[2].f = 2;
            dp[2].s = 1;
            dp[2].score = FSs[2].second + FSs[1].second;
        }
    }

    for(int i = 3; i <= N; i ++){
        int f = dp[i-1].f;
        int s = dp[i-1].s;
        long long current_score = dp[i-1].score;

        dp[i].f = f;
        dp[i].s = s;
        dp[i].score = current_score;

        //これまでの味が同じ場合
        if(FSs[f].first == FSs[s].first){
            //次の味も同じ場合は美味しさを比較するだけ
            if(FSs[f].first == FSs[i].first){
                if(FSs[f].second < FSs[i].second){
                    dp[i].f = i;
                    dp[i].s = f;
                    dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second / 2;
                    continue;
                }
                else if(FSs[s].second < FSs[i].second){
                    dp[i].f = f;
                    dp[i].s = i;
                    dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second / 2;
                    continue;
                }
            }
            else{
                if(FSs[s].second / 2 < FSs[i].second){
                    if(FSs[f].second < FSs[i].second){
                        dp[i].f = i;
                        dp[i].s = f;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second;
                        continue;
                    }
                    else{
                        dp[i].f = f;
                        dp[i].s = i;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second;
                        continue;
                    }
                }
            }
        }
        else{
            //一番大きい要素と味が違う場合
            if(FSs[f].first != FSs[i].first){
                if(FSs[s].second < FSs[i].second){
                    if(FSs[f].second < FSs[i].second){
                        dp[i].f = i;
                        dp[i].s = f;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second;
                        continue;
                    }
                    else{
                        dp[i].f = f;
                        dp[i].s = i;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second;
                        continue;
                    }
                }
            }
            //一番大きい要素と味が同じ場合
            else{
                if(FSs[f].second < FSs[i].second){
                    if(FSs[f].second / 2 < FSs[s].second){
                        dp[i].f = i;
                        dp[i].s = s;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second;
                        continue;
                    }
                    else{
                        dp[i].f = i;
                        dp[i].s = f;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second / 2;
                        continue;
                    }
                }
                else{
                    if(FSs[s].second < FSs[i].second / 2){
                        dp[i].f = f;
                        dp[i].s = i;
                        dp[i].score = FSs[dp[i].f].second + FSs[dp[i].s].second / 2;
                        continue;
                    }
                }
            }
        }
    }

    cout << dp[N].score << endl;;


    return 0;
}