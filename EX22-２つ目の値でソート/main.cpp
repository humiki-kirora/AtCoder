#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<tuple<int,int>> inputs(N);
    for(int i = 0; i < N; i ++){
        cin >> get<0>(inputs[i]) >> get<1>(inputs[i]);
    }

    sort(inputs.begin(),inputs.end(),
         [](tuple<int,int> const &left,tuple<int,int> const &right){ return get<1>(left) < get<1>(right);});

    for(auto input : inputs){
        printf("%d %d\n",get<0>(input),get<1>(input));
    }

    return 0;
}