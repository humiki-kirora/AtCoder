#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }
 
  bool check = false;

  for(int i = 1; i < 5; i ++) if(data[i - 1] == data[i]) {check = true; break;}

  if(check) cout << "YES" << endl;
  else cout << "NO" << endl;

}