#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int W,H,N;
    cin >> W >> H >> N;

    vector<pair<int,int>> ps(N);
    for(auto & p : ps) cin >> p.first >> p.second;

    int A,B;
    cin >> A;
    vector<int> as(A);
    for(auto & a : as) cin >> a;

    cin >> B;
    vector<int> bs(B);
    for(auto & b : bs) cin >> b;

    vector<vector<int>> matrix(H,vector<int>(W,0));
    for(auto & p : ps) matrix[p.second][p.first] ++;

    vector<vector<int>> cumsum(H + 1,vector<int>(W + 1,0));

    for(int h = 1; h < H + 1; h ++){
        for(int w = 1; w < W + 1; w ++){
            cumsum[h][w] = cumsum[h][w - 1] +  matrix[h - 1][w - 1];
        }
    }

    for(int h = 1; h < H + 1; h ++){
        for(int w = 1; w < W + 1; w ++){
            cumsum[h][w] = cumsum[h][w] + cumsum[h - 1][w]; 
        }
    }

    int maxs = 0;
    int mins = 1e+8;

    pair<int,int> prev_coord;
    prev_coord.first = prev_coord.second = 0;

    for(int i = 0; i < bs.size(); i++){

        for(int j = 0; j < as.size(); j++){
            pair<int,int> current_coord;
            current_coord.first = bs[i];
            current_coord.second = as[j];

            int res = cumsum[current_coord.first + 1][current_coord.second + 1] - 
                      cumsum[current_coord.first + 1][prev_coord.second] -
                      cumsum[prev_coord.first][current_coord.second + 1] +
                      cumsum[prev_coord.first][prev_coord.second];

            mins = min(res,mins);
            maxs = max(res,maxs);

            prev_coord.second = current_coord.second;
        }

        prev_coord.second = 0;
        prev_coord.first = bs[i];
    }

    cout << mins << " " << maxs << endl;

    return 0;
}