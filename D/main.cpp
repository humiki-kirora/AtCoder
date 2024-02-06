#include <bits/stdc++.h>
using namespace std;

/***type templete***/
#define ll long long
#define u32 unsigned int
#define u64 unsigned long long
#define d64 double
#define pii pair<int,int>
#define pci pair<char,int>

/***vector templete ***/
typedef vector<int> vi;
#define INTI_VI(N) vi(N,0)

typedef vector<u64> vu64;
#define INTI_VU64(N) vu64(N,0)

typedef vector<string> vs;
#define INTI_VS(N) vs(N)

typedef vector<vi> vvi;
#define INTI_VVI(H,W) vvi(H,vi(W,0))

typedef vector<vu64> vvu64;
#define INTI_VVU64(H,W) vvu64(H,vu64(W,0))


/***input template***/
template<class T>
void read_v(vector<T> & args){
    for(int i = 0; i < args.size(); i ++) cin >> args[i];
}

template<class T>
void read_vv(vector<vector<T>> & args){
    for(int i = 0; i < args.size(); i ++)
        for(int j = 0; j < args[0].size(); j ++) cin >> args[i][j];
}

/***output templete***/
template<class T>
void ANSWER(T ans, bool end = true){
    if(end) cout << ans << endl;
    else cout << ans << " ";
}

template<class T>
void ANSWER_ARRAY(vector<T> ans){
    for(int i = 0; i < ans.size() - 1; i ++){
        ANSWER(ans[i],false);
    }
    ANSWER(ans.back());
}

template<class T>
void ANSWER_ARRAYS(vector<vector<T>> ans){
    for(int i = 0; i < ans.size(); i ++){
        for(int j = 0; j < ans[0].size() - 1; j ++){
            ANSWER(ans[i][j],false);
        }
        ANSWER(ans[i].back());
    }
}

void YESorNO(bool ans){
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

void solve(){
    u64 N;
    cin >> N;

    auto S = INTI_VS(N);
    read_v(S);

    pair<int,int> ps[2];
    int c = 0;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(S[i][j] == 'P'){
                ps[c] = make_pair(i,j);
                c++;
            }
        }
    }

    bool check_root = false;
    auto map = INTI_VVI(N,N);
    queue<pair<int,int>> q;
    q.push(ps[0]);
    map[ps[0].first][ps[0].second] = 1;


    while(!q.empty()){
        auto p = q.front();
        int d = map[p.first][p.second];

        if(p.second - 1 >= 0 && map[p.first][p.second - 1] == 0){
            if(S[p.first][p.second - 1] == '#'){
                map[p.first][p.second - 1] = -1;
            }
            else{
                map[p.first][p.second - 1] = d + 1;
                q.push(make_pair(p.first,p.second - 1));
            }
        }

        if(p.first - 1 >= 0 && map[p.first - 1][p.second] == 0){
            if(S[p.first - 1][p.second] == '#'){
                map[p.first - 1][p.second] = -1;
            }
            else{
                map[p.first - 1][p.second] = d + 1;
                q.push(make_pair(p.first - 1,p.second));
            }
        }

        if(p.second + 1 < N && map[p.first][p.second + 1] == 0){
            if(S[p.first][p.second + 1] == '#'){
                map[p.first][p.second + 1] = -1;
            }
            else{
                map[p.first][p.second + 1] = d + 1;
                q.push(make_pair(p.first,p.second + 1));
            }
        }

        if(p.first + 1 < N && map[p.first + 1][p.second] == 0){
            if(S[p.first + 1][p.second] == '#'){
                map[p.first + 1][p.second] = -1;
            }
            else{
                map[p.first + 1][p.second] = d + 1;
                q.push(make_pair(p.first + 1,p.second));
            }
        }

        q.pop();
    }

    if(map[ps[1].first][ps[1].second] == 0){
        ANSWER(-1);
        return;
    }

    int ans = INT64_MAX;

    // h->v
    int p1 = 


}

int main(){
    solve();
    return 0;
}