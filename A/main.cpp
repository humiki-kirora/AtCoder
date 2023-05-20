#include <bits/stdc++.h>
using namespace std;

vector<int> calc_reverse(vector<int>& input,int L,int R){
    auto res = vector<int>(input);
    reverse(res.begin() + L, res.begin() + R + 1);
    return res;
}

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(auto & a : A) cin >> a;
    
    set<int> S;
    for(int i = 0; i < A.size(); i++){
        S.insert(A[i]);
    }

    int all = 0;;
    for(auto s : S){
        int start_itr = 0;
        int bias = 0;
        for(int i = 0; i < N; i ++){
            if(A[i] != s) {break;}
            start_itr++;
        }

        if(start_itr != 0){
            bias += ((N - start_itr) * (N - start_itr + 1) / 2) + ((start_itr) * (start_itr + 1) / 2) ;
        }


        vector<int> position;
        auto current_iter = A.begin() + start_itr;
        while((current_iter = find(current_iter,A.end(), s)) != A.end()){
            position.push_back(distance(A.begin(),current_iter));
            current_iter ++;
        }

        int sum = position.size();
        if(all + sum + bias < K){all += sum + bias; continue;}

        vector<vector<int>> answers;
        for(auto p:position){
            answers.push_back(calc_reverse(A,0,p));
        }

        if(answers.size() == 0){
            for(int i = start_itr; i < N; i ++){
                for(int j = start_itr; j < N; j++){
                    answers.push_back(calc_reverse(A,i,j));
                }
            }
        }

        int num = K - all;
        sort(answers.begin(),answers.end(),[](const vector<int> &alpha,const vector<int> &beta){
            for(int i = 0; i < alpha.size(); i++){
                if(alpha[i] != beta[i]) return alpha[i] < beta[i];
            }
            return alpha[0] < beta[0];
        });


        for(int i = 0; i < N - 1; i ++){
            cout << answers[num - 1][i] << " ";
        }
        cout << answers[num - 1][N - 1] << endl;

        return 0;
    }


    return 0;
}
