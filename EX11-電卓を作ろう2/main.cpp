#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  cin >> N >> A;

  for(int i = 1; i <= N; i ++){
    int B;
    string op;
    cin >> op >> B;

    if(op == "+"){
        A += B;
        cout << i << ":" << A << endl;
        continue;
    }
    else if(op == "-"){
        A -= B;
        cout << i << ":" << A << endl;
        continue;
    }
    else if(op == "*"){
        A *= B;
        cout << i << ":" << A << endl;
        continue;
    }
    else if(op == "/"){
        if(B == 0){
            cout << "error" << endl;
            break;
        }
        A /= B;
        cout << i << ":" << A << endl;
        continue;
    }
  }
}