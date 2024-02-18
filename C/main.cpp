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
    u64 N,W,H;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    auto S = INTI_VS(H);
    read_v(S);
    map<char,pair<int,int>> m;
    m['L'] = make_pair(0,-1);
    m['R'] = make_pair(0,1);
    m['U'] = make_pair(-1,0);
    m['D'] = make_pair(1,0);

    int ans = 0;
    for(int h = 1; h < H - 1; h ++){
        for(int w = 1; w < W - 1; w ++){
            if(S[h][w] != '.') continue;
            int c_pos_h = h;
            int c_pos_w = w;
            bool check = true;
            for(int i = 0; i < N; i ++){
                int n_pos_h = c_pos_h + m[T[i]].first;
                int n_pos_w = c_pos_w + m[T[i]].second;
                if(S[n_pos_h][n_pos_w] != '.'){
                    check = false;
                    break;
                }
                else{
                    c_pos_h = n_pos_h;
                    c_pos_w = n_pos_w;
                }
            }

            if(check){
                ans++;
            } 
        }
    }

    ANSWER(ans);
}

int main(){
    solve();
    return 0;
}