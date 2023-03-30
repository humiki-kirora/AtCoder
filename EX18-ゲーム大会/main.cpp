#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }
 
  // ここにプログラムを追記
  enum Result
  {
    WIN = 1,
    LOSE = -1,
    NO_GAME = 0,
  };

  vector<vector<Result>> results(N,vector<Result>(N,Result::NO_GAME));

  for(int i = 0; i < M; i ++){
    results[A[i] - 1][B[i] - 1] = Result::WIN;
    results[B[i] - 1][A[i] - 1] = Result::LOSE;
  }

  for(int i = 0; i < N; i ++){
    for(int j = 0; j < N; j ++){

        switch (results[i][j])
        {
        case Result::WIN:
            //○ではなくo
            cout << "o";
            break;

        case Result::LOSE:
            //×ではなくx
            cout << "x";
            break;

        case Result::NO_GAME:
            cout << "-";
            break;

        default:
            cout << "error";
            exit(-1);
            break;
        }

        if(j != N - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}