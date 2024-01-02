#include <iostream>

using namespace std;

int main() {
  const int div = 10007;
  int n;
  int tile[1001] = {0,};
  cin >> n;

  //초기값 설정
  tile[1] = 1;
  tile[2] = 2;

  for(int i = 3; i <= 1000; i++){
    tile[i] = (tile[i-1] % div + tile[i-2] % div) % div;
  }

  cout << tile[n];
}