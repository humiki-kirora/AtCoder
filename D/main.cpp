#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    string S;
    cin >> S;

    stack<int> pA;
    for(int i = S.size() - 1; i >= 2; i --){
        if(S.substr(i - 2, 3) == "ABC"){
            pA.push(i - 2);
            i -= 2;
        }
    }

    int count = 0;
    int size = S.size();
    while(!pA.empty() && S.size() >= 3){
        int i = pA.top() - count * 3;

        S.erase(S.begin() + i,S.begin() + i + 3);
        count ++;

        while(true){

            if(0 <= i - 1 && i + 2 < S.size()){
                if(S.substr(i - 1,3) == "ABC"){
                    S.erase(S.begin() + i - 1,S.begin() + i + 2);
                    count ++;
                    i --;
                    continue;
                }
            }

            if(0 <= i - 2 && i + 1 < S.size()){
                if(S.substr(i - 2,3) == "ABC"){
                    S.erase(S.begin() + i - 2,S.begin() + i + 1);
                    count ++;
                    i -= 2;
                    continue;
                }
            }

            break;
        }

        pA.pop();
    }

    cout << S << endl;
    return 0;
}