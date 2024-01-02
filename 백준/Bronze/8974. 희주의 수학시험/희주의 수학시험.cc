#include <iostream>

using namespace std;

int main() {
  int data[1005] = {};
  int a, b;
  cin >> a >> b;

  int cycle = 1; // 몇번 등장해야하는지 나타내는 값
  int temp = 0;  // 숫자가 등장한 횟수

  // 미리 데이터를 만들어 놓기
  for (int i = 1; i <= 1000; i++) {
    data[i] = cycle;
    temp++;

    if(temp == cycle){ // 숫자가 모두 등장했다면 다음 숫자로 바꿈
      cycle++;
      temp = 0;
    }
  }

  // a부터 b까지 누적합 계산
  int result = 0;
  for(int i = a; i <= b; i++){
    result += data[i];
  }

  cout << result;

  return 0;
}