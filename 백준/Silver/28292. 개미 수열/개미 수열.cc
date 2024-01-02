/*
  항을 적다보면 가장 길어질때는
  1이 1개(11) 이런식으로 2개씩 반복되며, 3개가 반복될떄는
  이런것 앞에 n이 1개가 오는경우이다.(2, 3도 마찬가지)
  그런데 n이 1이면 함께 포함되어 버리므로 불가능
  따라서 6번부터는 항상 3이다.
*/
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if(n <= 2) cout << 1;
  else if (n <= 5) cout << 2;
  else cout << 3;
}