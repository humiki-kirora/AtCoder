#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N;

    vector<int> D(N,0);
    for(int i =0 ; i < N; i ++) cin >> D[i];

    int count = 0;
    for(int i = 0; i < N; i ++){
        int num = (i + 1);

        int base_num = (i % 10) + 1;
        int tmp_num = num;
        bool check = true;
        while(tmp_num != 0){
            if(tmp_num % 10 != base_num){
                check = false;
                break;
            }

            tmp_num /= 10;
        }

        if(!check) continue;

        for(int j = base_num; j <= D[i]; j = j * 10 + base_num){
            count ++;
        }
    }

    cout << count << endl;
    return 0;
}