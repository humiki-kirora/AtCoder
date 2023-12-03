#include <bits/stdc++.h>
using namespace std;
#define ULLong unsigned long long
#define ULong unsigned long
#define LLong long long

int N,M,Q,K,T;

int main(){
    cin >> N >> Q;
    vector<string> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    vector<vector<ulong>> cumsum(N + 1,vector<ulong>(N + 1,0));

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            cumsum[i + 1][j + 1] = (P[i][j] == 'B' ? 1 : 0) + cumsum[i + 1][j];
        }
    }

    for(int i = 0; i < N; i ++){
        for(int j = 0; j <= N; j ++){
            cumsum[i + 1][j] = cumsum[i][j] + cumsum[i + 1][j];
        }
    }

    // for(int i = 0; i <= N; i ++){
    //     for(int j = 0; j < N; j ++){
    //         cout << cumsum[i][j] << " ";
    //     }
    //     cout << cumsum[i].back() << endl;        
    // }

    for(int i = 0; i < Q; i ++){
        int A,B,C,D;
        cin >> A >> B >> C >> D;

        ulong count = 0;
        int w = D - B + 1;
        int h = C - A + 1;
        int lmod = B % N;
        int rmod = D % N;
        int tmod = A % N;
        int bmod = C % N;
        int lspace = lmod == 0 ? 0 : N - lmod;
        int rspace = (rmod + 1) % N;
        int tspace = tmod == 0 ? 0 : N - tmod;
        int bspace = (bmod + 1) % N;
        int w_full = (w - lspace - rspace) / N;
        int h_full = (h - tspace - bspace) / N;

        // all
        ulong full = w_full * h_full;
        count += full * cumsum[N][N];

        //left
        count += h_full * (cumsum[N][N] - cumsum[N][N - lspace]);

        //right
        count += h_full * (cumsum[N][rspace]);

        //top
        count += w_full * (cumsum[N][N] - cumsum[N - tspace][N]);

        //bottom
        count += h_full * (cumsum[bspace][N]);

        //lt
        count += cumsum[N][N] - (cumsum[N - tspace][N] + cumsum[N][N - lspace]) + cumsum[N - tspace][N - lspace];

        //rt
        count += cumsum[N][rspace] - cumsum[N - tspace][rspace];

        //lb
        count += cumsum[bspace][N] - cumsum[bspace][N - lspace];

        //rb
        count += cumsum[bspace][rspace];

        cout << count << endl;
    }

    return 0;
}