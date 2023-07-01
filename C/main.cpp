#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int Ha,Wa;
    cin >> Ha >> Wa;
    vector<string> A(Ha);
    for(auto & a : A) cin >> a;
    bool check;

    pair<int,int> first_a, end_a;
    check = false;
    for(int i = 0; i < Ha; i ++){
        for(int j = 0; j < Wa; j ++){
            if(A[i][j] == '#'){
                first_a.first = j;
                first_a.second = i;
                check = true;
                break;
            }
        }
        if(check) break;
    }

    check = false;
    for(int i = Ha - 1; i >= 0; i ++){
        for(int j = Wa - 1; j >= 0; j ++){
            if(A[i][j] == '#'){
                end_a.first = j;
                end_a.second = i;
                check = true;
                break;
            }
        }
        if(check) break;
    }

    int Hb,Wb;
    cin >> Hb >> Wb;
    vector<string> B(Hb);
    for(auto & b : B) cin >> b;


    pair<int,int> first_b, end_b;
    check = false;
    for(int i = 0; i < Hb; i ++){
        for(int j = 0; j < Wb; j ++){
            if(B[i][j] == '#'){
                first_b.first = j;
                first_b.second = i;
                check = true;
                break;
            }
        }
        if(check) break;
    }

    check = false;
    for(int i = Hb - 1; i >= 0; i ++){
        for(int j = Wb - 1; j >= 0; j ++){
            if(B[i][j] == '#'){
                end_b.first = j;
                end_b.second = i;
                check = true;
                break;
            }
        }
        if(check) break;
    }

    int Hx,Wx;
    cin >> Hx >> Wx;
    vector<string> X(Hx);
    for(auto & x : X) cin >> x;

    pair<int,int> first_x, end_x;
    check = false;
    for(int i = 0; i < Hx; i ++){
        for(int j = 0; j < Wx; j ++){
            if(X[i][j] == '#'){
                first_x.first = j;
                first_x.second = i;
                check = true;
                break;
            }
        }
        if(check) break;
    }

    check = false;
    for(int i = Hx - 1; i >= 0; i ++){
        for(int j = Wx - 1; j >= 0; j ++){
            if(X[i][j] == '#'){
                end_x.first = j;
                end_x.second = i;
                check = true;
                break;
            }
        }
        if(check) break;
    }

    
    return 0;
}