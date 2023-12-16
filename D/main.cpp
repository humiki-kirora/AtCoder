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
#define INTI_VVI(N) vvi(N,vi(N,0))

typedef vector<vu64> vvu64;
#define INTI_VVU64(N) vvu64(N,vu64(N,0))
#define INTI_VVU64_HW(H,W) vvu64(H,vu64(W,0))


/***input template***/
template<class T>
void read_v(vector<T> & args){
    for(int i = 0; i < args.size(); i ++) cin >> args[i];
}

template<class T>
void read_vv(vector<vector<T>> & args){
    for(int i = 0; i < args.size(); i ++)
        for(int j = 0; j < args[i].size(); j ++) cin >> args[i][j];
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
        for(int j = 0; j < ans.size() - 1; j ++){
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
    u64 H,W;
    cin >> H >> W;

    auto A = INTI_VVU64_HW(H,W);
    read_vv(A);

    auto B = INTI_VVU64_HW(H,W);
    read_vv(B);

    // 0.探索用setの作成
    vector<set<int>> A_rows(H);
    vector<set<int>> B_rows(H);
    vector<set<int>> A_cols(W);
    vector<set<int>> B_cols(W);

    for(int i = 0; i  < H; i ++){
        for(int j = 0; j < W; j ++){
            A_rows[i].insert(A[i][j]);
            B_rows[i].insert(B[i][j]);
            A_cols[j].insert(A[i][j]);
            B_cols[j].insert(B[i][j]);
        }
    }

    auto row_pair = INTI_VI(H);
    auto col_pair = INTI_VI(W);
    vector<bool> checker(H,false);
    for(int i = 0; i  < H; i ++){
        for(int j = 0; j < H; j ++){
            if(checker[i]) continue;
            if(B_rows[i] == A_rows[j]){
                row_pair[i] = j;
                checker[i] = true;
                break;
            }

        }
    }

    if(find(checker.begin(),checker.end(),false) != checker.end()){
        cout <<  -1 << endl;
        return;
    }

    checker = vector<bool>(H,false);
    for(int i = 0; i  < W; i ++){
        for(int j = 0; j < W; j ++){
            if(checker[i]) continue;
            if(B_cols[i] == A_cols[j]){
                col_pair[i] = j;
                checker[i] = true;
                break;
            }
        }
    }

    if(find(checker.begin(),checker.end(),false) != checker.end()){
        cout <<  -1 << endl;
        return;       
    }

    int swap_count = 0;
    for(int i = 0; i  < H; i ++){
        int dist = distance(row_pair.begin(),find(row_pair.begin(),row_pair.end(),i));
        for(int j = dist; j > i; j --){
            row_pair[j] = row_pair[j - 1];
            swap_count ++;
        }
        row_pair[i] = i;
    }

    for(int i = 0; i  < H; i ++){
        int dist = distance(col_pair.begin(),find(col_pair.begin(),col_pair.end(),i));
        for(int j = dist; j > i; j --){
            col_pair[j] = col_pair[j - 1];
            swap_count ++;
        }
        col_pair[i] = i;
    }

    ANSWER(swap_count);
}

int main(){
    solve();
    return 0;
}