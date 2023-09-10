#include <bits/stdc++.h>
using namespace std;
#define ULLong unsingned long long
#define ULong unsingned long
#define LLong long long

int N,M,Q,K,T;
map<string,int> ranker;

int main(){
    ranker.insert(pair<string,int>("tourist",3858));
    ranker.insert(pair<string,int>("ksun48",3679));
    ranker.insert(pair<string,int>("Benq",3658));
    ranker.insert(pair<string,int>("Um_nik",3648));
    ranker.insert(pair<string,int>("apiad",3638));
    ranker.insert(pair<string,int>("Stonefeang",3630));
    ranker.insert(pair<string,int>("ecnerwala",3613));
    ranker.insert(pair<string,int>("mnbvmar",3555));
    ranker.insert(pair<string,int>("newbiedmy",3516));
    ranker.insert(pair<string,int>("semiexp",3481));

    string S;
    cin >> S;

    cout << ranker[S] << endl;

    return 0;
}