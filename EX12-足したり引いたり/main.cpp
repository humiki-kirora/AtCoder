#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;

  int size = S.size();
  int A = 1;
  for(int i = 1; i < size; i += 2){
    if(S.at(i) == '+'){
      A++;
      continue;
    }
    else{
      A--;
      continue;
    }
  }

  cout << A << endl;

  return 0;
}