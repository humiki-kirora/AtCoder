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
    auto A = INTI_VI(N - 1);
    auto B = INTI_VI(N - 1);
    auto X = INTI_VI(N - 1);
    read_v(A);
    read_v(B);
    read_v(X);

    vector<int> dp(N,INT32_MAX);
    map<int,int> B_min;
    dp[0] = 0;

    bool check = true;

    do{
        check = true;
        for(int x = 1; x < N; x ++){
            int tmp_c = dp[x];
            int tmp_x = dp[X[x]];
            dp[x] = min(dp[x],dp[x - 1] + A[x - 1]);
            if(dp[x] != tmp_c) check = false;

            if(x != N - 1){
                dp[X[x]] = min(dp[X[x]],dp[x] + B[x]);
                if(dp[X[x]] != tmp_x) check = false;
            }
        }
        ANSWER_ARRAY(dp);
    } while(!check);

    ANSWER_ARRAY(dp);

    cout << dp[N - 1] << endl;
}

int main(){
    solve();
    return 0;
}