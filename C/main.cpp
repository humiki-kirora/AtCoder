
#include <bits/stdc++.h>
using namespace std;

int main(){
    //文字列の取得
    string S,T;
    cin >> S >> T;

    const string change = "atcoder";

    set<char> already_ch;

    int S_at = count(S.begin(),S.end(),'@');
    int T_at = count(T.begin(),T.end(),'@');

    for(auto s : S){
        //@は無視
        if(s == '@') continue;
        //探索済みも無視
        if(already_ch.find(s) != already_ch.end()) continue;
        already_ch.insert(s);

        int S_ch = count(S.begin(),S.end(),s);
        int T_ch = count(T.begin(),T.end(),s);
        //二つの列で同じ要素数なら無視
        if(S_ch == T_ch) continue;

        if(change.find(s) == string::npos){
            cout << "No" << endl;
            return 0;
        }
        else{
            if(S_ch > T_ch){
                int sub =  S_ch - T_ch;
                T_at -= sub;
                if(T_at < 0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            else{
                int sub =  T_ch - S_ch;
                S_at -= sub;
                if(S_at < 0){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    for(auto s : T){
        //@は無視
        if(s == '@') continue;
        //探索済みも無視
        if(already_ch.find(s) != already_ch.end()) continue;
        already_ch.insert(s);

        int S_ch = count(S.begin(),S.end(),s);
        int T_ch = count(T.begin(),T.end(),s);
        //二つの列で同じ要素数なら無視
        if(S_ch == T_ch) continue;

        if(change.find(s) == string::npos){
            cout << "No" << endl;
            return 0;
        }
        else{
            if(S_ch > T_ch){
                int sub =  S_ch - T_ch;
                T_at -= sub;
                if(T_at < 0){
                    cout << "No" << endl;
                    return 0;
                }
            }
            else{
                int sub =  T_ch - S_ch;
                S_at -= sub;
                if(S_at < 0){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}