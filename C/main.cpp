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


/***input template***/
template<class T>
void read_v(vector<T> & args){
    for(int i = 0; i < args.size(); i ++) cin >> args[i];
}

template<class T>
void read_vv(vector<vector<T>> & args){
    for(int i = 0; i < args.size(); i ++)
        for(int j = 0; j < args.size(); j ++) cin >> args[i][j];
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
    u64 N,M;
    cin >> N >> M;

    string S;
    cin >> S;

    int max_T = 0;

    auto current_itr = S.begin();
    do{
        auto next_itr = find(current_itr,S.end(),'0');
        int logo = count(current_itr,next_itr,'2');
        int length = distance(current_itr,next_itr);

        //cout << length << logo << endl;
        int ans = 0;
        ans += logo;
        if(M < length - logo){
            ans += length - logo - M;
        }

        if(max_T < ans){
            max_T = ans;
        }

        if(next_itr == S.end()) break;
        current_itr = next_itr + 1;

    } while(current_itr != S.end());

    ANSWER(max_T);
}

int main(){
    solve();
    return 0;
}