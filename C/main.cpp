#include <bits/stdc++.h>
using namespace std;

int N,M,H,W,Q,K,T;
int ans = 0;
void calc_max_length(vector<vector<pair<int,int>>>& graph, int current_pos, int sum,vector<bool> &check){
    ans = max(sum,ans);
    
    check[current_pos] = true;
    for(int i = 0; i < graph[current_pos].size(); i ++){
        if(!check[graph[current_pos][i].first]) calc_max_length(graph,
                                                                graph[current_pos][i].first,
                                                                sum + graph[current_pos][i].second,
                                                                check);
    }
    check[current_pos] = false;
}

int main(){
    cin >> N >> M;

    vector<vector<pair<int,int>>> g(N + 1);
    vector<bool> check(M + 1,false);
    for(int i = 0; i < M; i ++){
        int A,B,C;
        cin >> A >> B >> C;
        g[A].push_back(pair<int,int>(B,C));
        g[B].push_back(pair<int,int>(A,C));
    }

    for(int i = 1; i <= N; i ++){
        calc_max_length(g,i,0,check);
    }

    cout << ans << endl;
    return 0;
}