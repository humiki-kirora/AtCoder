#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;

  vector<int> scores(N);
  int average = 0;
  for(int i = 0; i < N; i ++){
    cin >> scores[i];
    average += scores[i];
  }

  average /= N;

  for(int i = 0; i < N; i ++){
    cout << abs(scores[i] - average) << endl;
  }

  return 0;
}