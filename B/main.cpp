#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for(int i = 0; i < N; i ++){
        cin >> S[i];
    }

    vector<pair<int,int>> answers;

    for(int i = 0; i <= N - 9; i ++){
        for(int j = 0; j <= M - 9; j ++){
            bool check = true;

            for(int s_i = i; s_i < i + 4; s_i ++){
                for(int s_j = j; s_j < j + 4; s_j ++){
                    if(s_i == i + 3 || s_j == j + 3){
                        if(S[s_i][s_j] != '.'){
                            check = false;
                            continue;
                        }
                    }
                    else{
                        if(S[s_i][s_j] != '#'){
                            check = false;
                            continue;
                        }
                    }
                }
                if(!check) continue;
            }

            if(!check) continue;

            for(int s_i = i + 5; s_i < i + 9; s_i ++){
                for(int s_j = j + 5; s_j < j + 9; s_j ++){

                    if(s_i == i + 5 || s_j == j + 5){
                        if(S[s_i][s_j] != '.'){
                            check = false;
                            continue;
                        }
                    }
                    else{
                        if(S[s_i][s_j] != '#'){
                            check = false;
                            continue;
                        }
                    }
                }
                if(!check) continue;
            }

            if(!check) continue;

            cout << i + 1 << " " << j + 1 << endl;
        }
    }

    return 0;
}