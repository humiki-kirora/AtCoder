#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int M;
    cin >> M;

    vector<int> D(M + 1);
    int sum = 0;
    for(int i = 1; i <= M; i ++){
        cin >> D[i];
        sum += D[i];
    }

    int center_day = sum / 2 + 1;

    for(int i = 1; i <= M; i++){
        if(center_day - D[i] > 0){
            center_day -= D[i];
            continue;
        }

        cout << i << " " << center_day << endl;
        break;
    }
    return 0;
}