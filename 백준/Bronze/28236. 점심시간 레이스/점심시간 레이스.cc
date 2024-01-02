#include <iostream>

using namespace std;

int main() {
  int n ,m, k, minTime = 200002, winClass;

  cin >> n >> m >> k;

  //아래로 이동하는 시간 층수 -1
  //옆으로 이동하는 시간 반개수 + 1 - 현재반
  for(int i = 0; i < k; i++){
    int a, b, tempTime;
    cin >> a >> b;
  
    tempTime = (a - 1) + (m + 1 - b);

    if(tempTime < minTime){
      winClass = i + 1;
      minTime = tempTime;
    }
  }

  cout << winClass;
}
