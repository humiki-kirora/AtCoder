#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;
    string S;
    cin >> S;

    set<char> apper_char;
    map<char,int> apper_count;

    for(int i = 0; i < N; i ++){
        char get_char = S[i];
        apper_char.insert(get_char);
        if(apper_count.find(get_char) == apper_count.end()){
            apper_count[get_char] = 1;
        }

        int j = i + 1;
        while(S[j] == get_char){
            j ++;
        }
        apper_count[get_char] = j - i > apper_count[get_char] ? j - i : apper_count[get_char];
        i = j - 1;
    }

    int count = 0;

    for(auto c : apper_char){
        int num = apper_count[c];
        count += num;
    }

    cout << count << endl;
    return 0;
}