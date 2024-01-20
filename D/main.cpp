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

int pir_serch(vu64 & A,int pos,int current,int N,int comp, int direction){
    if(pos + direction < 0 || pos + direction == N) return current;

    if(comp - A[pos + direction] > 0){
        return pir_serch(A,pos + direction,current + 1,N, A[pos + direction],direction);
    }
    else if(comp - current >= 0){
        comp = comp - 1;
        if(comp > 0){
            return pir_serch(A,pos + direction,current + 1,N, comp, direction);
        }
        else{
            return current;
        }
    }
    else{
        return current;
    }
}

void solve(){
    u64 N,M,K,Q;
    cin >> N;

    auto A = INTI_VU64(N);
    read_v(A);
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> que;

    if(A[0] - A[1] > 0) que.push(pair<int,int>(A[0],0));
    if(A[N - 1] - A[ N -2] > 0) que.push(pair<int,int>(A[N - 1],N - 1));

    for(int i = 1; i < N - 1 ; i ++){
        if( A[i] - A [i - 1] >= 0 &&
            A[i] - A [i + 1] >= 0){
                que.push(pair<int,int>(A[i],i));
            }
    }

    u64 ans = 0;

    while(!que.empty()){
        auto t = que.top();
        if(t.first <= ans) break;

        int left = pir_serch(A,t.second,0,N,t.first,-1);
        int right = pir_serch(A,t.second,0,N,t.first,1);

        if(ans < min(left,right)){
            ans = min(left,right);
        }
        que.pop();
    }

    ANSWER(ans + 1);
}

int main(){
    solve();
    return 0;
}