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

void search_max(map<int,vector<int>> & g,map<int,bool> & checks, int i,int & ans){
    if(!checks[i]) return;
    else checks[i] = false;

    if(ans < i){
        ans = i;
    }

    for(auto j = 0; j < g[i].size(); j ++){
        search_max(g,checks,g[i][j],ans);
    }
}

void solve(){
    int H,W;
    cin >> H >> W;
    auto S = INTI_VS(H);
    auto T = INTI_VS(H);
    read_v(S);
    read_v(T);
    vector<string> St(W,string(H,'a'));
    vector<string> Tt(W,string(H,'a'));

    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            St[j][i] = S[i][j];
            Tt[j][i] = T[i][j];
        }
    }

    map<string,int> Sm;
    map<string,int> Tm;

    for(int i = 0; i < W; i ++){
        if(Sm.find(St[i]) == Sm.end()){
            Sm[St[i]] = 1;
        }
        else{
            Sm[St[i]] ++;
        }

        if(Tm.find(Tt[i]) == Tm.end()){
            Tm[Tt[i]] = 1;
        }
        else{
            Tm[Tt[i]] ++;
        }
    }

    for(auto s : Sm){
        if(Tm.find(s.first) == Tm.end()){
            YESorNO(false);
            return;
        }

        if(Tm[s.first] != s.second){
            YESorNO(false);
            return;
        }
    }

    YESorNO(true);



}

int main(){
    solve();
    return 0;
}