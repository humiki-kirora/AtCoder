#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> A(N,vector<int>(N));

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B(N,vector<int>(N));    

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            cin >> B[i][j];
        }
    }

    bool check = true;

    //0
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(A[i][j]){
                if(!B[i][j]){check = false; break;}
            }
        }
    }

    if(check) {cout << "Yes" << endl; return 0;}

    check = true;

    //右90度
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(A[N - 1 - j][i]){
                if(!B[i][j]){check = false; break;}
            }
        }
    }

    if(check) {cout << "Yes" << endl; return 0;}

    check = true;
    //180度
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(A[N - 1 - i][N - 1 - j]){
                if(!B[i][j]){check = false; break;}
            }
        }
    }

    if(check) {cout << "Yes" << endl; return 0;}

    check = true;

    //270度
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(A[j][N - 1 - i]){
                if(!B[i][j]){check = false; break;}
            }
        }
    }

    if(check) {cout << "Yes" << endl; return 0;}

    cout << "No" << endl;
    return 0;
}