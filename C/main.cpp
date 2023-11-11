#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    vector<vector<int>> A(9,vector<int>(9,0));
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            cin >> A[i][j];
        }    
    }

    vector<set<int>> col(9,set<int>());
    vector<vector<set<int>>> matrixs(3,vector<set<int>>(3,set<int>()));

    for(int i = 0; i < 9; i ++){
        set<int> row;
        for(int j = 0; j < 9; j ++){
            row.insert(A[i][j]);
            col[j].insert(A[i][j]);
            matrixs[i / 3][j / 3].insert(A[i][j]);
        }
        if(row.size() != 9){
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 9; i ++){
        if(col[i].size() != 9){
            cout << "No" << endl;
            return 0;
        }
    }

   for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(matrixs[i][j].size() != 9){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}