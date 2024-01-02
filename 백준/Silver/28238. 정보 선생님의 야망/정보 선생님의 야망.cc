#include <iostream>

using namespace std;

int main() {
  int studentNum, tempStudent, ans;
  int maxStudent[5][5] = {};
  int date[5] = {};
  int answer[5] = {};

  cin >> studentNum;

  // 0  1  2  3  4
  // 월 화 수 목 금
  for(int k = 0; k < studentNum; k++){
    for(int i = 0; i < 5; i++){
      cin >> date[i];
    }
 
    for(int i = 0; i < 5; i++){
      for(int j = i + 1; j < 5; j++){
        if(date[i] == 1 && date[j] == 1)
          maxStudent[i][j] += 1;
      }
    }
  }

  ans = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      tempStudent = maxStudent[i][j];

      if(ans < tempStudent){
        ans = tempStudent;
        for(int k = 0 ; k < 5; k++){
          if(k == i || k == j) answer[k] = 1;
          else answer[k] = 0;
        }
      }
    }
  }

  if(ans == 0){
    cout << ans << "\n";
    cout << "1 1 0 0 0";
  }
  else{
    cout << ans << "\n";
    for(int i = 0; i < 5; i++){
      cout << answer[i] << ' ';
    }
  }
}
