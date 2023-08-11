#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N, M;
    cin >> N >> M;
    vector<set<int>> Player(N + 1);

    for(int i = 0; i < M; i ++){
        int A,B;
        cin  >> A >> B;
        Player[A].insert(B);
    }

    vector<bool> winners(N + 1,true);
    for(int i = 1; i <= N; i ++){
        for(auto &p : Player[i]){
            winners[p] = false;
        }
    }

    int winner_num = 0;
    int winner;
    for(int i = 1; i <= N; i ++){
        if(winners[i]){
            winner_num ++;
            winner = i;
        }
    }

    if(winner_num != 1){
        cout << -1 << endl;
    }
    else{
        cout << winner << endl;
    }
    
    return 0;
}