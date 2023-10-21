#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin  >> N;
    string T;
    cin >> T;

    vector<string> S(N);
    vector<int> ans;
    for(int i = 0; i < N; i ++) cin >> S[i];
    int t_size = T.size();
    
    for(int i = 0; i < N; i ++){
        int sub = t_size - int(S[i].size());
        if(sub < -1 || 1 < sub) continue;

        if(sub == 0){
            int count = 0;
            for(int j = 0; j < t_size; j ++){
                if(S[i][j] != T[j]){
                    count ++;
                    if(count > 1){
                        break;
                    }
                }
            }

            if (count < 2){
                ans.push_back(i + 1);
            }
        }
        else{
            int count = 0;

            if(t_size > S[i].size()){
                for(int j1 = 0, j2 = 0; j1 < t_size; j1 ++,j2 ++){
                    if(S[i][j2] != T[j1]){
                        count ++;
                        if(count > 1){
                            break;
                        }
                        j1 ++;
                        if(S[i][j2] != T[j1]){
                            count ++;
                            break;
                        }
                    }
                }
            }
            else{
                for(int j1 = 0, j2 = 0; j1 < t_size; j1 ++,j2 ++){
                    if(S[i][j2] != T[j1]){
                        count ++;
                        if(count > 1){
                            break;
                        }
                        j2 ++;
                        if(S[i][j2] != T[j1]){
                            count ++;
                            break;
                        }
                    }
                }
            }


            if (count < 2){
                ans.push_back(i + 1);
            }

        }
    }

    cout << ans.size() << endl;

    if(ans.size() != 0){
        for(int i = 0; i < ans.size() - 1; i ++){
            cout << ans[i] << " ";
        }

        cout << ans.back() << endl;
    }
    else{
        cout << endl;
    }

    return 0;
}