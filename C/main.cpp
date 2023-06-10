#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N,D;
    cin >> N >> D;

    vector<pair<int,int>> coord(N);
    for(auto & c : coord) cin >> c.first >> c.second;

    int check_dist = D * D;
    vector<int> virus;
    vector<bool> result(N,false);

    virus.push_back(0);
    result[0] = true;

    int current_size = 0;
    do {
        for(int i = 0; i < N; i ++){
            if(result[i]) continue;
            int dist = pow(coord[virus[current_size]].first - coord[i].first,2) + pow(coord[virus[current_size]].second - coord[i].second,2);
            if(dist <= check_dist){
                virus.push_back(i);
                result[i] = true;
            }
        }
        current_size++;
    }while(current_size != virus.size());

    for(int i = 0; i < result.size(); i ++){
        if(result[i]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}