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
何か拗らせて変な工夫をしようとしてここで時間切れになった...  
流石にABCが間に合わないのは酷いので反省

```


```

