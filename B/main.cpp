#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    string S;
    cin >> S;

    int prev_num = atoi(S.substr(0,2).c_str());
    int next_num = atoi(S.substr(2,2).c_str());
    if(0 < prev_num && prev_num <= 12){
        if(0 < next_num && next_num <= 12){
            cout << "AMBIGUOUS" << endl;
            return 0;
        }
        else{
            cout << "MMYY" << endl;
            return 0;
        }
    }
    else {
        if(0 < next_num && next_num <= 12){
            cout << "YYMM" << endl;
            return 0;
        }
        else{
            cout << "NA" << endl;
            return 0;
        }
    }

    return 0;
}