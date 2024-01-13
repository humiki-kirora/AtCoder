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
    u64 N,Q;
    cin >> N >> Q;

    auto dragon = vector<pair<int,int>>();
    dragon.push_back(pair<int,int>(1,0));

    for(int q = 0; q < Q; q ++){
        int f_q;
        cin >> f_q;

        if(f_q == 1){
            char s_q;
            cin >> s_q;
            int next_x,next_y;

            if(s_q == 'R'){
                next_x = dragon.back().first + 1;
                next_y = dragon.back().second;
            }
            else if(s_q == 'L'){
                next_x = dragon.back().first - 1;
                next_y = dragon.back().second;
            }
            else if(s_q == 'U'){
                next_x = dragon.back().first;
                next_y = dragon.back().second + 1;
            }
            else{
                next_x = dragon.back().first;
                next_y = dragon.back().second - 1;
            }
            dragon.push_back(pair<int,int>(next_x,next_y));

        }
        else{
            int s_q;
            cin >> s_q;
            pair<int,int> place(s_q,0);
            int moves = dragon.size();
            if(moves - 1 < s_q){
                ANSWER(place.first - (moves - 1),false);
                ANSWER(place.second);
            }
            else{
                int m = place.first - 1;
                ANSWER(dragon[(moves - 1) - m].first,false);
                ANSWER(dragon[(moves - 1) - m].second);
            }
        }
    }

}

int main(){
    solve();
    return 0;
}