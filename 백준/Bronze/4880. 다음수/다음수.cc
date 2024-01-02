#include <iostream>

using namespace std;

int main() {
  int a, b, c;

  while(true){
    cin >> a >> b >> c;

    if(a == 0 && b == 0 && c == 0)
      break;

    if(a + c == b * 2){ // 등차수열인 경우
      cout << "AP " << c + (c - b) << '\n';
    }
    else{ // 등비수열인 경우
      cout << "GP " << c * c / b << '\n';
    }
  }
}