#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

bool check_321_like(ULong num,ULLong& dims){
    ULong prev = num % 10;
    num /= 10;
    while(num != 0){
        int mod = num % 10;
        if(prev >= mod){
            return false;
        }
        dims ++;
        prev = mod;
        num /= 10;
    }
    return true;
}

ULLong N,M,Q,K,T;

int main(){
    cin >> K;
    int count = 0;
    ULong current_num = 1;
    ULong prev_num;
    while(count != K){
        ULLong dim = 1;

        ULLong tmp_num = current_num;
        bool check = true;
        ULong prev = tmp_num % 10;
        tmp_num /= 10;
        while(tmp_num != 0){
            int mod = tmp_num % 10;
            if(prev >= mod){
                check = false;
                break;
            }
            dim ++;
            prev = mod;
            tmp_num /= 10;
        }

        if(!check){
            current_num += 10ULL * dim - (current_num % ( 10ULL * dim));
            for(ULLong i = 0; i < dim; i ++){
                current_num += i * (1 << (dim - 1));
            }
        }
        else{
            count ++;
            prev_num = current_num;
            current_num ++;
        }
    }

    cout << prev_num << endl;
    return 0;
}