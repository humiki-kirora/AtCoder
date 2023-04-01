#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    std::cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i ++){
        cin >> A[i];
    }

    map<int,int> dict;

    for(auto data : A){
        dict[data]++;
    }

    int max = 0;
    int key = 0;
    for(auto data : dict){
        if (max < data.second) {max = data.second; key = data.first;}
    }

    cout <<  key << " " << max << endl;

    return 0;
}