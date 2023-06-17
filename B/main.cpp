#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    char p,q;
    cin >> p >> q;

    vector<int> points = {3,1,4,1,5,9};
    vector<char> point_name = {'A','B','C','D','E','F','G'};

    int s = distance(point_name.begin(),find(point_name.begin(),point_name.end(),p));
    int e = distance(point_name.begin(),find(point_name.begin(),point_name.end(),q));

    if(s > e){
        int emp = s;
        s = e;
        e = emp;
    }

    int ans = 0;
    for(int i = s; i < e; i ++){
        ans += points[i];
    }

    cout << ans << endl;
    return 0;
}