#include <bits/stdc++.h>
using namespace std;

ulong N,M,Q,K,T;

int main(){
    cin >> N >> Q;
    vector<ulong> A(N);
    for(int i = 0; i < N; i ++) cin >> A[i];

    map<ulong,int> dict;
    set<ulong> current_num;
    for(int i = 0; i < N; i ++){
        if(dict.find(A[i]) == dict.end()){
            dict[A[i]] = 1;
        }
        else{
            dict[A[i]] ++;
        }

        current_num.insert(A[i]);
    }

    for(int q = 0; q < Q; q ++){
        ulong i,k;
        cin >> i >> k;

        dict[A[i - 1]] --;
        if(dict[A[i - 1]] == 0) current_num.erase(A[i - 1]);
        A[i - 1] = k;

        if(dict.find(k) == dict.end()){
            dict[k] = 1;
        }
        else{
            dict[k] ++;
        }
        current_num.insert(k);

        auto itr = current_num.begin();
        ulong ans = *itr;
        if(ans != 0){
            cout << 0 << endl;
            continue;
        }

        itr ++;
        bool check = false;
        while(itr != current_num.end()){
            ulong next = *itr;
            if(next - ans > 1){
                cout << ans + 1 << endl;
                check = true;
                break;
            }
            
            ans = next;
            itr ++;
        }

        if(!check) cout << ans + 1 << endl;
    }


    return 0;
}