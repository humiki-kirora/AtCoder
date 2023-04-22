#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<vector<int>> box(N,vector<int>(0));

    for(int i = 0; i < Q; i ++){
        string S;
        cin >> S;

        if(S[0] == 1){
            int i = atoi(&S[2]);
            int j = atoi(&S[4]);
            box[j].push_back(i);

        }
        else if(S[0] == 2){
            int i = atoi(&S[2]);
            sort(box[i].begin(),box[i].end());
            for(int k = 0; k < box[i].size(); k++){
                cout << box[i][k];
                if(k == box[i].size() - 1){cout << endl;}
                else{cout << " ";}
            }
        }
        else{
            int i = atoi(&S[2]);
            for(int k = 0; k < N; k ++){
                if(find(box[k].begin(),box[k].end(),i) != box[k].end()){
                    cout << k;
                    if(k != N - 1){cout << " ";}
                }
            }
            cout << endl;
        }
    }


    return 0;
}