#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T,X,Y;

int main(){
    cin >> X >> Y;

    if(0 <= X - Y && X - Y <= 3){
        cout <<"Yes" << endl;
        return 0;
    }
    else if(0 <= Y - X && Y - X <= 2){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}