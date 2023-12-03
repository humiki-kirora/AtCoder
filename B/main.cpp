#include <bits/stdc++.h>
using namespace std;

ulong N,S,M,L;

int main(){
    cin >> N >> S >> M >> L;

    int ans[3];
    ulong current = ULONG_MAX;

    for(int x = 0; x <= (N / 6) + 1; x ++){
        for(int y = 0; y <= (N / 8) + 1; y ++){
            for(int z = 0; z <= (N / 12) + 1; z++){
                int count = x * 6 + y * 8 + z * 12;
                if(count < N) continue;
                int value = x * S + y * M + z * L;
                if(current > value){
                    current = value;
                }
            }
        }
    }

    cout << current << endl;
    return 0;
}