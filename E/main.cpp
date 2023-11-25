#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;
    string S,T,SR(N,'#'),TR(M,'#');
    cin >> S >> T;

    map<char,set<int>> dict;
    for(int i = 0; i < T.size(); i ++){
        if(dict.find(T[i]) == dict.end()){
            dict[T[i]] = set<int>();
        }

        dict[T[i]].insert(i);
    }

    bool update = false;
    do{
        update = false;
        for(int i = 0; i < N; i ++){
            if(S[i] == '#') continue;
            int index = 0;
            for(auto idx : dict[S[i]]){
                index = idx;
                bool check = true;
                for(int j = 0; j < M; j ++){
                    if(S[i - idx + j] != '#' && S[i - idx + j] != T[j]){
                        check = false;
                        break;
                    }
                }
                if(!check) continue;

                S.replace(i - idx,M,TR);
                update = true;
                break;
            }
        }

    }while(update);

    if(SR == S){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    
    return 0;
}