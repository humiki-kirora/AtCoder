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

u64 gcd(u64 a,u64 b){
    int mod = a % b;
    if(mod == 0) return b;
    else return gcd(b,mod);
}

u64 lcm(u64 a,u64 b){
    return a / gcd(a,b) * b;
} 

void solve(){
    u64 N,M,K;
    cin >> N >> M >> K;
    u64 lcms = lcm(N,M);
    u64 n_count = (lcms / N) - 1;
    u64 m_count = (lcms / M) - 1;
    u64 lcm_num = n_count + m_count;

    u64 p = (K - 1) / lcm_num;
    u64 start_v = p * lcms;
    u64 current_count = p * lcm_num;
    u64 ans = 0;
    u64 n_i = 1;
    u64 m_i = 1;

    while(current_count < K){
        if(start_v + N * n_i < start_v + M * m_i){
            ans = start_v + N * n_i;
            n_i ++;
        }
        else{
            ans = start_v + M * m_i;
            m_i ++;
        }
        current_count ++;
    }

    ANSWER(ans);
}

int main(){
    solve();
    return 0;
}