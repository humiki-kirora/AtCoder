#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(char* str,int L,int R){

    int split = (R - L) / 2;
    
    if ( L == R ){
        return;
    }

    //L型の分割・マージ
    merge_sort(str,L, L + split);

    //R側の分割・マージ
    merge_sort(str,L + split + 1,R);

    int l_count = split;
    int r_count = R - (L + split + 1);
    while(true){

    }

}

int main(){
    int N,Q;

    cin >> N >> Q;

    char* s;
    s = new char[N];

    for(int i = 0; i < N; i++) s[i] = (char)('A' + i);

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N - 1; j ++){
            printf("? %c %c\n",s[j],s[j + 1]);
            fflush(stdout);
            char ans;
            scanf(" %c",&ans);
            if(ans == '>') swap(s[j],s[j + 1]);
        }
    }

    printf("! %s\n",s);

    delete[] s;

    return 0;

}