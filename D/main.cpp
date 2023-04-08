#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e+18

int main(){
    long long N,M,ans = INF;
    cin >> N >> M;

    //条件1:X = ab (1 <= a,b <= N)
    //条件2:M <= X

    /*解説*/
    /*a<=bを前提に考える*/
    /*aを1,...,Nまで動かす際に,その時にM<=Xで最小となるbはb=(M // a)※切り上げ*/
    /*a>√Mまで行ったところで,a>bとなるので、これ以上は考えなくてよい*/
    /*仮に√M = aの時にまでにb>N以上になる場合はあるか?→その際にはa > Nになっているのでどのみち条件を満たさない*/
    /*したがって、1<=a<=√Mの範囲でN > b,b=(M // a)となるを満たすabの最小値を見つければよい*/

    /*ただしfor文は1<=a<=√Mではなく,1<=a<=Nで回す(√M > Nのケースがあるのと,a=bの時が計算されない場合がある)*/
    /*例:N=11 M=111の時,root_M = 10,a=10の時はb = 12だが,b>Nよりはじかれる。
    /*a<=√Mの範囲であればここで終わりだが、実際にはa=b=11の時、a,b<=NかつM<=a*bを満たす為、このケースを無視してしまう*/
    /*そのため、1<=a<=Nの範囲でa>bの段階まできちんと検証してあげる必要がある*/
    
    long long root_M = sqrt(M);

    for(long long a = 1; a <= N; a ++){
        long long b = ceil(M / (double)a);

        if(a > b) break;
        if(b > N) continue;
        if(ans == INF) ans = a * b;
        ans = min(ans,a*b);
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}