
#include <bits/stdc++.h>
using namespace std;

int main(){
    //回数の取得
    int N;
    cin >> N;

    //文字列の取得
    string S;
    cin >> S;

    int count_T = 0;
    int count_A = 0;
    int first = 0;

    for(auto s : S){
        if(s == 'T'){
            count_T ++;
        }
        else{
            count_A ++;
        }
        if(count_T < count_A){
            first = 1;
        }
        if(count_T > count_A){
            first = 0;
        }
    }

    if(count_T > count_A){
        cout << "T" << endl; 
    }
    else if (count_T == count_A){
        if(first == 0){
            cout << "T" << endl; 
        }
        else{
            cout << "A" << endl; 
        }
    }
    else{
        cout << "A" << endl;    
    }

    return 0;
}