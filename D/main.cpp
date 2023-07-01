#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    //文字列の取得
    string S;
    cin >> S;

    stack<int> stacks_light;

    for(int i = 0; i < S.size(); i ++){
        if('(' == S[i]) stacks_light.push(i);
        if(')' == S[i] && (stacks_light.size() != 0)){
            int l = stacks_light.top();
            S.erase(l,i + 1 - l);
            i = l - 1;
            stacks_light.pop();
        } 
    }

    cout << S << endl;

    return 0;
}