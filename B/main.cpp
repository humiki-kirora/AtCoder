#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;

    struct Rect{
        int A,B,C,D;
    };

    vector<struct Rect> rect(N);

    int minx = 101;
    int maxx = 0;
    int miny = 101;
    int maxy = 0;

    for(int i = 0; i < N; i ++) {
        cin >> rect[i].A >>  rect[i].B >>  rect[i].C >>  rect[i].D;
        if(rect[i].A < minx){
            minx = rect[i].A;
        }
        if(rect[i].C < miny){
            miny = rect[i].C;
        }
        if(rect[i].B > maxx){
            maxx = rect[i].B;
        }
        if(rect[i].D > maxy){
            maxy = rect[i].D;
        }
    }

    vector<vector<bool>> check(maxy,vector<bool>(maxx,false));
    for(auto r : rect){
        for(int i = r.C; i < r.D; i ++){
            for(int j = r.A; j < r.B; j ++){
                check[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i = miny; i < maxy; i ++){
        for(int j = minx; j < maxx; j ++){
            ans += check[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}