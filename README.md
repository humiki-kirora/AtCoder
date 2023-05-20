# ABC302
https://atcoder.jp/contests/abc302/tasks  
ABCDまで完答　1000点

## A Attack
普通にA%Bを行い、余りがある場合は1を足す  
ただし、データ型には注意が必要(一敗)

## B Find snuke
開始点のsを起点に、8方向にそれぞれnukeと続くかどうかを探索すればよい

## C Almost Equal
自分の回答：
1. 二つの文字列のコンビネーション全通りで移行できるかを判定して、状態遷移行列を作成する
2. ある文字列を起点にそこから遷移できるすべての文字列をsetに格納
3. すべての文字列が格納された場合、全部繋がっているので遷移が可能と判定できる  
これで正解できたが、実際には例外がある気がするので正答の全通り探索が一番良い気がする  

### next_permitation
与えられた時点のイテレータ範囲[first, last)を起点の順列として、辞書順によるその次の順列を生成する関数  
ソートした行列においてこの関数を使う事で、すべての順列を自動的に探索することが可能
```C++
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  sort(s.begin(),s.end());
  do{
    bool ok=true;
    for(int i=0;i<n-1;i++){
      int cnt=0;
      for(int j=0;j<m;j++) if(s[i][j]!=s[i+1][j]) cnt++;
      if(cnt!=1) ok=false;
    }
    if(ok){
      cout<<"Yes"<<endl;
      return 0;
    }
  }while(next_permutation(s.begin(),s.end()));
  cout<<"No"<<endl;
}
```

## D Impartial Gift
最大値同士で差分を取り、D以下の場合その組み合わせが自動的に最大値として判定できる  
そうでないなら、大きい方の要素を削除して、また最大値同士で差分を取っていき、それをどちらかの集合が空集合になるまで繰り返す  
空集合になってしまった場合、差分がD以下の組み合わせがないことがわかる