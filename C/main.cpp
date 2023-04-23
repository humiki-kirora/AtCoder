#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> post;
    auto current_itr = S.begin();
    while((current_itr = find(current_itr,S.end(),'-')) != S.end()){
        post.push_back(distance(S.begin(),current_itr));
        current_itr ++;
    }
    if (post.size() == 0) {cout << -1 << endl; return 0;}

    int max = post[0];

    for(int i = 0; i < post.size() - 1; i ++){
        if(max < post[i + 1] - post[i] - 1){
            max = post[i + 1] - post[i]  - 1;
        }
    }

    if(max < (N - 1)  - post[post.size() - 1]) max = (N - 1)  - post[post.size() - 1];

    if(max == 0){
        cout << -1 << endl;
        return 0;
    }

    cout << max << endl;
    return 0;
}