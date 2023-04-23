#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,T;
    cin >> N >> T;

    vector<int> C(N);
    vector<int> R(N);

    for(int i = 0; i < N; i ++ ){
        cin >> C[i];
    }

    for(int i = 0; i < N; i ++ ){
        cin >> R[i];
    }

    //condition1,findT;
    int max = -1;
    int Player = -1;
    auto current_itr = C.begin();

    while((current_itr = find(current_itr,C.end(),T)) != C.end()){
        if(max < R[distance(C.begin(),current_itr)]){
            max = R[distance(C.begin(),current_itr)];
            Player = distance(C.begin(),current_itr) + 1;
        }
        current_itr ++;
    }

    if(max != -1) {cout << Player << endl; return 0;}

    //condition2
    T = C[0];
    max = R[0];
    Player = 1;
    current_itr = C.begin();

    while((current_itr = find(current_itr,C.end(),T)) != C.end()){
        if(max < R[distance(C.begin(),current_itr)]){
            max = R[distance(C.begin(),current_itr)];
            Player = distance(C.begin(),current_itr) + 1;
        }
        current_itr ++;
    }

    cout << Player << endl; 

    return 0;
}