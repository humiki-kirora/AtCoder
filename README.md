# AtCoder
AtCoderの各コンテストについての回答・解説を保存しておくレポジトリ

# 運用
- 各コンテストごとにブランチを作成して作業
- 言語は基本的にC,C++,pythonのいずれか
- 学習が完了したコンテストについてはタグを打つ予定 
  
# テンプレート

C++
```C++
#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    //文字列の取得
    string S;
    cin >> S;

    //配列の取得
    //1次元
    vector<int> A(N);
    for(auto & a : A) cin >> a;

    //2次元(数値)
    vector<vector<int>> B(N,vector<int>(N,0));
    for(auto & b : B)
        for(auto & e : b)
            cin >> e;

    //2次元(文字列)
    vector<string> Ss;
    for(auto & s : Ss) cin >> s;

    //答えの出力
    cout << "Yes" << endl;
    return 0;
}
```