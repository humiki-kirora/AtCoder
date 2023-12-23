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

class Union_Find{
    vector<int> parent;
    vector<int> size;
    int num;

    public:
    Union_Find(int N){
        num = N;
        parent = vector<int>(N + 1, -1);
        size = vector<int>(N + 1,1);
    }

    void init(){
        for(int i = 0; i <= num; i ++){
            parent[i] = -1;
            size[i] = 1;
        }
    }

    int root(int x){
        while(true){
            if(parent[x] == -1) break;
            x = parent[x];
        }
        return x;
    }

    void integrate(int u,int v){
        int root_u = root(u);
        int root_v = root(v);
        if(root_u == root_v) return;
        if(size[root_u] < size[root_v]){
            parent[root_u] = root_v;
            size[root_v] = size[root_v] + size[root_u];
        }
        else{
            parent[root_v] = root_u;
            size[root_u] = size[root_v] + size[root_u];
        }
        return;
    }

    bool equal(int u,int v){
        return root(u) == root(v); 
    }

};

void min_serch(int N, vector<set<int>> & graph, int & num){
    if(graph[N].size() == 0){
        num ++;
        return;
    }
    else{
        for(auto g : graph[N]){
            graph[g].erase(N);
            min_serch(g,graph,num);
        }
        num ++;
    }
    return;
}

void solve(){
    u64 N,M,K,Q;
    cin >> N;

    vector<pair<int,int>> v(N);
    for(int i = 0; i < N - 1; i ++) cin >> v[i].first >> v[i].second;

    vector<set<int>> graph(N);
    for(int i = 0; i < N - 1; i ++){
        graph[v[i].first - 1].insert(v[i].second - 1);
        graph[v[i].second - 1].insert(v[i].first - 1);
    }


    int min_num = INT32_MAX;
    if(graph[0].size() == 1){
        ANSWER(1);
        return ;
    }

    vector<int> answers(graph[0].size(),0);

    int i = 0;
    for(auto g : graph[0]){
        int num = 0;
        graph[g].erase(0);
        min_serch(g,graph,num);
        answers[i] = num;
        i++;
    }

    sort(answers.begin(),answers.end());
    int ans = 0;
    for(int i = 0; i < answers.size() - 1; i ++){
        ans += answers[i];
    }

    ANSWER(ans + 1);
}

int main(){
    solve();
    return 0;
}