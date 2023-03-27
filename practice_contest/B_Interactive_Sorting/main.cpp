#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

char answer(char s1, char s2){
    printf("? %c %c\n",s1,s2);
    fflush(stdout);

    char ans;
    scanf(" %c",&ans);

    return ans;
}

/*マージソート(部分点):N=5,Q=7のケースで条件を満たせていない*/
void merge_sort(char* str,int L,int R){

    if ( L == R ){
        return;
    }

    int split = (R - L) / 2;

    //L型の分割・マージ
    merge_sort(str,L, L + split);

    //R側の分割・マージ
    merge_sort(str,L + split + 1,R);

    //マージソート
    char *start, *l_merge, *r_merge;

    start = str + L;
    int l_count = split + 1;
    int r_count = R - (L + split);
    int current_l = 0;
    int current_r = 0;

    l_merge = new char[l_count];
    memcpy(l_merge, start, l_count * sizeof(char));

    r_merge = new char[r_count];
    memcpy(r_merge,start + l_count,r_count * sizeof(char));

    while(true){

        if(current_l == l_count){
            memcpy(start,r_merge + current_r, (r_count - current_r) * sizeof(char));
            break;
        }
        
        if(current_r == r_count){
            memcpy(start,l_merge + current_l, (l_count - current_l) * sizeof(char));
            break;
        }

        printf("? %c %c\n",l_merge[current_l],r_merge[current_r]);
        fflush(stdout);
        
        char ans;
        scanf(" %c",&ans);
        
        if(ans == '>'){
            start[0] = r_merge[current_r];
            current_r ++;
        }
        else{
            start[0] = l_merge[current_l];
            current_l ++;
        }

        start ++;
    }

    delete[] l_merge;
    delete[] r_merge;

    return;

}

/*N=5 Q=7用の最小比較ソートアルゴリズム*/
void N_5_Q_7_sort(char* str){
    char tmp_str[5];
    memcpy(tmp_str,str,5 * sizeof(char));
    char ans;

    //1回目 AB比較
    if(answer(tmp_str[0],tmp_str[1]) == '>'){
        swap(tmp_str[0],tmp_str[1]);
    }

    //2回目 CD比較
    if(answer(tmp_str[2],tmp_str[3]) == '>'){
        swap(tmp_str[2],tmp_str[3]);
    }

    //3回目 1・2回目の小さい方同士を比較
    if(answer(tmp_str[0],tmp_str[2]) == '>'){
        //4回目 真ん中の要素とEを比較 ok
        if(answer(tmp_str[0],tmp_str[4]) == '>'){
            //5回目 ok
            if(answer(tmp_str[2],tmp_str[4]) == '>'){
                //6回目 ok
                if(answer(tmp_str[3],tmp_str[0]) == '>'){
                    //7回目 ok
                    if(answer(tmp_str[3],tmp_str[1]) == '>'){
                        str[0] = tmp_str[4];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[0];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[3];
                    }
                    else{
                        str[0] = tmp_str[4];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[0];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[1];
                    }

                }
                else{
                    str[0] = tmp_str[4];
                    str[1] = tmp_str[2];
                    str[2] = tmp_str[3];
                    str[3] = tmp_str[0];
                    str[4] = tmp_str[1];
                }
            
            }
            else{
                //6回目 ok
                bool sixth = false;
                printf("? %c %c\n",tmp_str[3],tmp_str[0]);
                fflush(stdout);

                scanf(" %c",&ans);
                sixth = (ans == '>');

                if(sixth){
                    //7回目 ok
                    bool seventh = false;
                    printf("? %c %c\n",tmp_str[3],tmp_str[1]);
                    fflush(stdout);

                    scanf(" %c",&ans);
                    seventh = (ans == '>');

                    if(seventh){
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[4];
                        str[2] = tmp_str[0];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[3];
                    }
                    else{
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[4];
                        str[2] = tmp_str[0];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[1];
                    }

                }
                else{
                    //7回目 ok
                    bool seventh = false;
                    printf("? %c %c\n",tmp_str[3],tmp_str[4]);
                    fflush(stdout);

                    scanf(" %c",&ans);
                    seventh = (ans == '>');

                    if(seventh){
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[4];
                        str[2] = tmp_str[3];
                        str[3] = tmp_str[0];
                        str[4] = tmp_str[1];
                    }
                    else{
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[3];
                        str[2] = tmp_str[4];
                        str[3] = tmp_str[0];
                        str[4] = tmp_str[1];
                    }
                }
            
            }

        }
        else{
            //5回目 ok
            bool fifth = false;
            printf("? %c %c\n",tmp_str[1],tmp_str[4]);
            fflush(stdout);

            scanf(" %c",&ans);
            fifth = (ans == '>');

            if(fifth){
                //6回目ok
                bool sixth = false;
                printf("? %c %c\n",tmp_str[3],tmp_str[4]);
                fflush(stdout);

                scanf(" %c",&ans);
                sixth = (ans == '>');

                if(sixth){
                    //7回目 ok
                    bool seventh = false;
                    printf("? %c %c\n",tmp_str[3],tmp_str[1]);
                    fflush(stdout);

                    scanf(" %c",&ans);
                    seventh = (ans == '>');

                    if(seventh){
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[4];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[3];
                    }
                    else{
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[4];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[1];
                    }

                }
                else{
                    //7回目 ok
                    bool seventh = false;
                    printf("? %c %c\n",tmp_str[3],tmp_str[0]);
                    fflush(stdout);

                    scanf(" %c",&ans);
                    seventh = (ans == '>');

                    if(seventh){
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[3];
                        str[3] = tmp_str[4];
                        str[4] = tmp_str[1];
                    }
                    else{
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[3];
                        str[2] = tmp_str[0];
                        str[3] = tmp_str[4];
                        str[4] = tmp_str[1];
                    }
                }
            
            }
            else{
                //6回目
                bool sixth = false;
                printf("? %c %c\n",tmp_str[3],tmp_str[1]);
                fflush(stdout);

                scanf(" %c",&ans);
                sixth = (ans == '>');

                if(sixth){
                    //7回目 ok
                    bool seventh = false;
                    printf("? %c %c\n",tmp_str[3],tmp_str[4]);
                    fflush(stdout);

                    scanf(" %c",&ans);
                    seventh = (ans == '>');

                    if(seventh){
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[1];
                        str[3] = tmp_str[4];
                        str[4] = tmp_str[3];
                    }
                    else{
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[1];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[4];
                    }

                }
                else{
                    //7回目 
                    bool seventh = false;
                    printf("? %c %c\n",tmp_str[3],tmp_str[0]);
                    fflush(stdout);

                    scanf(" %c",&ans);
                    seventh = (ans == '>');

                    if(seventh){
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[3];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[4];
                    }
                    else{
                        str[0] = tmp_str[2];
                        str[1] = tmp_str[3];
                        str[2] = tmp_str[0];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[4];
                    }
                }
            
            }

        }

    }
    else{
        //4回目 真ん中の要素とEを比較 ok
        if(answer(tmp_str[2],tmp_str[4]) == '>'){
            //5回目 ok
            if(answer(tmp_str[0],tmp_str[4]) == '>'){
                //6回目 ok
                if(answer(tmp_str[1],tmp_str[2]) == '>'){
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[3]) == '>'){
                        str[0] = tmp_str[4];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[2];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[1];
                    }
                    else{
                        str[0] = tmp_str[4];
                        str[1] = tmp_str[0];
                        str[2] = tmp_str[2];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[3];
                    }

                }
                else{
                    str[0] = tmp_str[4];
                    str[1] = tmp_str[0];
                    str[2] = tmp_str[1];
                    str[3] = tmp_str[2];
                    str[4] = tmp_str[3];
                }
            
            }
            else{
                //6回目 ok
                if(answer(tmp_str[1],tmp_str[2]) == '>'){
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[3]) == '>'){
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[4];
                        str[2] = tmp_str[2];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[1];
                    }
                    else{
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[4];
                        str[2] = tmp_str[2];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[3];
                    }

                }
                else{
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[4]) == '>'){
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[4];
                        str[2] = tmp_str[1];
                        str[3] = tmp_str[2];
                        str[4] = tmp_str[3];
                    }
                    else{
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[1];
                        str[2] = tmp_str[4];
                        str[3] = tmp_str[2];
                        str[4] = tmp_str[3];
                    }
                }
            
            }

        }
        else{
            //5回目 ok
            if(answer(tmp_str[3],tmp_str[4]) == '>'){
                //6回目 ok
                if(answer(tmp_str[1],tmp_str[4]) == '>'){
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[3]) == '>'){
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[4];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[1];
                    }
                    else{
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[4];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[3];
                    }

                }
                else{
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[2]) == '>'){
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[1];
                        str[3] = tmp_str[4];
                        str[4] = tmp_str[3];
                    }
                    else{
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[1];
                        str[2] = tmp_str[2];
                        str[3] = tmp_str[4];
                        str[4] = tmp_str[3];
                    }
                }
            
            }
            else{
                //6回目 ok
                if(answer(tmp_str[1],tmp_str[3]) == '>'){
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[4]) == '>'){
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[3];
                        str[3] = tmp_str[4];
                        str[4] = tmp_str[1];
                    }
                    else{
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[3];
                        str[3] = tmp_str[1];
                        str[4] = tmp_str[4];
                    }

                }
                else{
                    //7回目 ok
                    if(answer(tmp_str[1],tmp_str[2]) == '>'){
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[2];
                        str[2] = tmp_str[1];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[4];
                    }
                    else{
                        str[0] = tmp_str[0];
                        str[1] = tmp_str[1];
                        str[2] = tmp_str[2];
                        str[3] = tmp_str[3];
                        str[4] = tmp_str[4];
                    }
                }
            
            }

        }
    }

    return ;
}

int main(){
    int N,Q;

    cin >> N >> Q;

    char* s;
    s = new char[N];

    for(int i = 0; i < N; i++) s[i] = (char)('A' + i);

    if(N != 5){
        merge_sort(s,0,N - 1);
    }
    else{
		N_5_Q_7_sort(s);
    }

    printf("! %s\n",s);

    delete[] s;

    return 0;

}
