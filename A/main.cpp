#include <bits/stdc++.h>
using namespace std;
#define INF 1e+8

int find_root(vector<vector<int>> &list,vector<int> &find,int s,int t){
    int N = list.size();

    if(std::find(list[s].begin(),list[s].end(),t) != list[s].end()){
        return 1;
    }

    for(int i = 0; i < list[s].size(); i ++){
        if(std::find(find.begin(),find.end(),list[s][i]) == find.end()){
            find.push_back(list[s][i]);
            int count = find_root(list,find,list[s][i],t);
            if(count != INF){
                return count + 1;
            }
        }
    }

    return INF;
}

int main(){
    int N,K,Q;
    cin >> N >> K;
    vector<vector<int>> A(N,vector<int>(N,0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    vector<vector<int>> root(N,vector<int>(N,0));
    vector<vector<int>> list(N,vector<int>(0));
    
    //解法：A内の最短経路を解ければ恐らくおｋ
    //隣接リストの作成
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(A[i][j] != 0) list[i].push_back(j);
        }
    }


    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            vector<int> find(0);
            root[i][j] = find_root(list,find,i,j);
        }

    }

    //Question
    cin >> Q;
    for(int i = 0; i < Q; i ++){
        int s,t;
        cin >> s >> t;

        if(root[(s - 1) % N][(t - 1) % N] != INF)
            cout << root[(s - 1) % N][(t - 1) % N] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}