# ABC300　復習
## A.N-choice question
N個のCからA+Bの答えを探すだけ。正解
```
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> C(N);
    for(int i = 0; i < N; i ++){
        cin >> C[i];
    }

    int ans = A + B;

    auto itr = find(C.begin(),C.end(),ans);
    
    cout << distance(C.begin(),itr) + 1 << endl;

    return 0;
}
```

## B.Same Map in the RPG World
H*Wの配列AとBが与えられ、以下の1と2の操作を続けて行い、A=Bにできるかどうかを判定する
- (1) 行を上方向にずらす操作をs回
- (2) 列を左方向にずらす操作をt回  

配列がH*Wなので、`0 <= s < H`　`0 <= t < W`の回数で全ての通りが計算可能  
何か拗らせて変な工夫をしようとしてここで時間切れになった...  普通に全探索で大丈夫だった
流石にABCが間に合わないのは酷いので反省
タイムアップ後に解いた回答

```
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

```

