#include <bits/stdc++.h>
using namespace std;


/*配列から探索対象のインデックスを全て取得する*/
vector<int> find_all_index(string s,char target){
    vector<int> result;
    auto current_itr = s.begin();

    while((current_itr = find(current_itr,s.end(),target)) != s.end()){
        result.push_back(distance(s.begin(),current_itr));
        current_itr ++;
    }

    return result;
}

vector<int> find_all_index(vector<int> s,int target){
    vector<int> result;
    auto current_itr = s.begin();

    while((current_itr = find(current_itr,s.end(),target)) != s.end()){
        result.push_back(distance(s.begin(),current_itr));
        current_itr ++;
    }

    return result;
}


int main(){

    return 0;
}