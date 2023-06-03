#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N,M,H,K;
    cin >> N >> M >> H >> K;

    string S;
    cin >> S;

    map<int,vector<int>> Items;
    for(int i = 0; i < M; i ++) {
        int x,y;
        cin >> x >> y;
        Items[x].push_back(y);
    }

    int current_HP = H;
    vector<int> current_p(2,0);
    

    for(auto & s : S){
        switch(s){
            case 'R' : current_p[0] ++; break;
            case 'L' : current_p[0] --; break;
            case 'U' : current_p[1] ++; break;
            case 'D' : current_p[1] --; break;
            default  : break;
        }

        current_HP --;

        if(current_HP < 0){
            cout << "No" << endl;
            return 0;
        }

        if(current_HP < K){
            auto x_itr = Items.find(current_p[0]);
            if(x_itr != Items.end()){
                auto y_itr = find(x_itr->second.begin(),x_itr->second.end(),current_p[1]);
                if(y_itr != x_itr->second.end()){
                    current_HP = K;
                    x_itr->second.erase(y_itr);
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}