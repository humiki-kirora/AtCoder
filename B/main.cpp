#include <bits/stdc++.h>
using namespace std;

int main(){
    const int TABLE = 8;
    vector<string> strs(TABLE);
    string col_name = "abcdefgh";

    for(int i = 0; i < TABLE; i ++){
        cin >> strs[i];
    }

    int row = 0;
    int col = 0;
    for(int i = 0; i < TABLE; i ++){
        auto pos = strs[i].find("*");
        if(pos != string::npos){
            row = i;
            col = pos;
            break;
        }
    }

    cout << col_name[col] << TABLE - row << endl;

    return 0;
}