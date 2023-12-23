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

int calc_pattern1(int i){
    if(i == 1){
        return 1;
    }
    else if(i == 2){
        return 4;
    }
    else{
        int pattern = 0;
        pattern += i;
        pattern += i * (i - 1);
        pattern += (i * (i - 1) * (i - 2)) / 6; 
        return pattern;
    }
}

int calc_pattern2(int i){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return 1;
    }
    else{
        int pattern = 0;
        pattern += i;
        pattern += i * (i - 1) / 2;
        return pattern;
    }
}

void solve(){
    u64 N;
    cin >> N;

    int i = 1;
    u64 a = 0,b = 0,c = 0;

    if(N == 1){
        ANSWER(3);
        return;
    }

    while(true){
        if(calc_pattern1(i) >= N){
            break;
        }
        else{
            i ++;
        }
    }


    for(int j = 0; j < i; j ++){
        a += pow(10,j);
    }

    int tmpN = N - calc_pattern1(i - 1);

    i = 1;
    while(true){
        if(calc_pattern2(i)>= tmpN){
            break;
        }
        else{
            i ++;
        }
    }

    for(int j = 0; j < i; j ++){
        b += pow(10,j);
    }

    tmpN = tmpN - calc_pattern2(i - 1);

    for(int j = 0; j < tmpN; j ++){
        c += pow(10,j);
    }

    ANSWER(a + b + c);
}

int main(){
    solve();
    return 0;
}