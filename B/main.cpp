#include <bits/stdc++.h>
using namespace std;

void row_shift(vector<vector<char>> &A){
    auto tmp = A[0];
    for(int i = 0; i < A.size() - 1; i ++){
        A[i] = A[i+1];
    }
    A[A.size() - 1] = tmp;
}


void col_shift(vector<vector<char>> &A){
    for(int i = 0; i < A.size(); i ++){
        auto tmp = A[i][0];
        for(int j = 0; j < A[0].size() - 1; j ++){
            A[i][j] = A[i][j+1];
        }
        A[i][A[0].size() - 1] = tmp;
    }
}

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<char>> A(H,vector<char>(W,0));
    vector<vector<char>> B(H,vector<char>(W,0));

    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < H; i ++){
        for(int j = 0; j < W; j ++){
            cin >> B[i][j];
        }
    }

    for(int i = 0; i <= H; i ++){
        row_shift(A);
        for(int j = 0; j <= W; j ++){
            col_shift(A);
            if(A == B){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }


    cout << "No" << endl;
    return 0;
}