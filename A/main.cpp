#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    vector<int> P(N);
    for(auto & p : P) cin >> p;

    int max = 0;
    bool check_double = false;
    for(int i = 0; i < P.size(); i ++){
        if(max < P[i]){
            max = P[i];
            check_double = false;
        }
        else if(max == P[i]){
            check_double = true;
        }
    }

    if(max == P[0]) {
        if(check_double){
          cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return 0;
    }

    cout << max - P[0] + 1 << endl;
    return 0;
}