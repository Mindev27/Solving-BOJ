#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  
  while(T--){    // 테스트 케이스 만큼 반복
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) // n번 반복
      cout << "=";

    cout << '\n';  // 개행
  }

  return 0;
}
