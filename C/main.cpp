/*Clear 2023/04/09*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> S(H);

    for(int i = 0; i < H; i ++) cin >> S[i];

    for(int i = 0; i < H; i ++){
        int check = 0;
        while(check <= (W - 1)){

            check = S[i].find("TT",check);

            if(check != string::npos){
                S[i][check] = 'P';
                S[i][check + 1] = 'C';
                check += 2;
            }
            else{
                break;
            }
        }
    }

    for(auto s : S) cout << s << endl;

    return 0;
}