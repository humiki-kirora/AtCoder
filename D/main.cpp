#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int X,Y,Z;
    cin >> X >> Y >> Z;

    string S;
    cin >> S;
    vector<string> small_S;
    auto itr = S.begin();
    auto current_ch = S[0];
    auto current_p = 0;
    for(int i = 0; i < S.size(); i ++){
        if(current_ch != S[i]){
            small_S.push_back(S.substr(current_p,((i - 1)  - current_p) + 1));
            current_ch = S[i];
            current_p = i;
        }
    }
    small_S.push_back(S.substr(current_p,S.size() - current_p));

    bool current_cap = false;
    int current_time = 0;

    for(auto & s : small_S){
        bool change = ((s[0] == 'a') && current_cap) || ((s[0] == 'A') && !current_cap);
        int size = s.size();

        if(!change){
            current_time += X * size;
        }
        else{
            int change_time = Z + X * size;
            int nochange_time = Y * size;

            if(change_time < nochange_time){
                current_time += change_time;
                current_cap = !current_cap;
            }
            else{
                current_time += nochange_time;
            }
        }
    }

    cout << current_time << endl;

    return 0;
}