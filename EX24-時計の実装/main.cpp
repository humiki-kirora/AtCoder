#include <bits/stdc++.h>
using namespace std;

// 以下に、24時間表記の時計構造体 Clock を定義する
typedef struct Clock_tag{
    int hour;
    int minute;
    int second;

    void set(int h,int m,int s){
        hour = h;
        minute = m;
        second = s;
    }

    string to_str(){
        char str[256];
        string strs;

        sprintf(str,"%02d:%02d:%02d",hour,minute,second);
        strs = str;

        return strs;
    }

    void shift(int diff_second){
        const int day_second = 23 * 3600 + 59 * 60 + 60;
        int current_second = hour * 3600 + minute * 60 + second;
        
        int next_second = (current_second + diff_second) % day_second;

        if(next_second < 0){
            next_second = day_second + next_second;
        }

        hour = next_second / 3600;
        minute = (next_second - (hour * 3600)) / 60;
        second = (next_second - (hour * 3600) - (minute * 60));
    }

} Clock;


// -------------------
// ここから先は変更しない
// -------------------

int main() {
  // 入力を受け取る
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock構造体のオブジェクトを宣言
  Clock clock;

  // set関数を呼び出して時刻を設定する
  clock.set(hour, minute, second);

  // 時刻を出力
  cout << clock.to_str() << endl;

  // 時計を進める(戻す)
  clock.shift(diff_second);

  // 変更後の時刻を出力
  cout << clock.to_str() << endl;
}
