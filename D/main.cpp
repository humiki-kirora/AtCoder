#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<int,int> qa;
    int start = 1;
    int end = N;

    for(int i = 0 ; i < 20; i ++){
        int q = start + (end - start) / 2;
        int a;
        printf("? %d\n",q);
        cin >> a;
        flush(cout);
        if(a == 1){
            end = q;
        }
        else{
            start = q;
        }

        if(end - start == 1){
            break;
        }
    }

    printf("! %d\n",start);

    return 0;
}