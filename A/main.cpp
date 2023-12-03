#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T,L,D;

int main(){
    cin >> M >> D;
    
    int y,m,d;
    cin >> y >> m >> d;

    int yd,md,dd;
    int increment = 0;

    if(d != D){
        dd = d + 1;
    }
    else{
        dd = 1;
        increment = 1;
    }

    if(increment != 0){
        if(m != M){
            md = m + 1;
            increment = 0;
        }
        else{
            md = 1;
            increment = 1;
        }
    }
    else{
        md = m;
        increment = 0;
    }

    yd = y + increment;

    cout << yd << " " << md << " " << dd << endl;
    return 0;
}