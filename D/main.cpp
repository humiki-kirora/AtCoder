#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> M;
    struct data{
        int A,B,X,Y;
    };

    vector<struct data> datas(M);
    for(int i = 0; i < M; i ++){
        cin >> datas[i].A >> datas[i].B >> datas[i].X >> datas[i].Y;
    }

    struct person{
        int x,y;
        bool detect = false;
    };

    vector<struct person> persons(N + 1);

    persons[1].x = persons[1].y = 0;
    persons[1].detect = true;

    bool update_num = datas.size();

    do {
        update_num = datas.size();
        for(int i = 0; i < datas.size(); i ++){
            int a = datas[i].A;
            int b = datas[i].B;
            if(persons[a].detect || persons[b].detect){
                if(persons[a].detect && persons[b].detect) {datas.erase(datas.begin() + i); i --; continue;}

                if(persons[a].detect){
                    persons[b].x = persons[a].x + datas[i].X; 
                    persons[b].y = persons[a].y + datas[i].Y; 
                    persons[b].detect = true;
                }
                else{
                    persons[a].x = persons[b].x - datas[i].X; 
                    persons[a].y = persons[b].y - datas[i].Y; 
                    persons[a].detect = true;
                }
                datas.erase(datas.begin() + i);
                i --;
            }    

        }

    }while(datas.size() != update_num);

    for(int i = 1; i <= N; i ++){
        if(persons[i].detect) cout << persons[i].x << " " << persons[i].y << endl;
        else cout << "undecidable" << endl;
    }

    return 0;
}