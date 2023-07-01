#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    //文字列の取得
    vector<string> S(N);
    for(auto & s : S) cin >> s;

    for(int i = 0; i < S.size(); i ++){

        for(int j = 0; j < S.size(); j ++){
            if(i == j) continue;
            string tmp_S = S[i] + S[j];

            bool check = true;
            for(int k = 0; k < tmp_S.size() / 2; k ++){
                if(tmp_S[k] != tmp_S[tmp_S.size() - 1 - k]){
                    check = false;
                    break;
                }
            }

            if(check) {
                cout << "Yes" << endl;
                return 0;
            }
        }

    }

    cout << "No" << endl;

    return 0;
}