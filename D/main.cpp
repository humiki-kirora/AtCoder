#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;


inline bool find_numbers(vector<int>& X, vector<pair<int,int>> &p, int current_index){
    // cout << "index:" << current_index << endl;
    if(current_index == p.size()) return true;
    
    int A = p[current_index].first - 1;
    int B = p[current_index].second - 1;

    if(A == B) return false;

    int fx = X[A];
    int sx = X[B];
    // cout << "A:" << A << " " << "B:" << B << endl;
    // cout << "fx:" << fx << " " << "sx:" << sx << endl;
    // cout << " " << endl;

    // check
    if(fx != -1 && fx == sx) return false;
    
    // 既に埋まっているのであれば次の組みを見る
    if(fx != -1 && sx != -1) return find_numbers(X,p,current_index + 1);

    // 両方側が設定されていない場合
    if(fx == -1 && sx == -1){
        X[A] = 0;
        X[B] = 1;
        if(find_numbers(X,p,current_index + 1)){
            return true;
        }

        X[A] = 1;
        X[B] = 0;
        if(!find_numbers(X,p,current_index + 1)){
            X[A] = -1;
            X[B] = -1;
            return false;
        }
        else{
            return true;
        }
    }

    // sx側が設定されていない場合
    if(fx != -1 && sx == -1){
        int num = (fx == 0);
        X[B] = num;
        if(!find_numbers(X,p,current_index + 1)){
            X[B] = -1;
            return false;
        }
        else{
            return true;
        }
    }

    // fx側が設定されていない場合
    if(fx == -1 && sx != -1){
        int num = (sx == 0);
        X[A] = num;
        if(!find_numbers(X,p,current_index + 1)){
            X[A] = -1;
            return false;
        }
        else{
            return true;
        }
    }

    return false;
}

int main(){
    cin >> N >> M;
    vector<int> A(M,0);
    vector<int> B(M,0);
    vector<pair<int,int>> p(M);

    for(int i = 0; i < M; i ++){
        cin >> A[i];
    }

    for(int i = 0; i < M; i ++){
        cin >> B[i];
    }

    for(int i = 0; i < M; i ++){
        p[i] = pair<int,int>(A[i],B[i]);
    }

    sort(p.begin(),p.end(),[](pair<int,int> &a ,pair<int,int> &b){return a.first < b.first;});
    // for(int i = 0; i < M; i ++){
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
    vector<int> X(N,-1);

    if(find_numbers(X,p,0)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}