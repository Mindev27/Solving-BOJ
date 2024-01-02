#include <iostream>

using namespace std;

int main() {
  int a, b, c, length, max_length;

  cin >> a >> b >> c;

  max_length = 0;
  
  for(int i = 1; i <= a; i++){
    for(int j = 1; j <= b; j++){
      for(int k = 1; k <= c; k++){
        if(i+j > k && j+k > i && k+i > j){ //삼각 부등식
          length = i + j + k;
          max_length = max_length < length ? length : max_length;
        }
      }
    }
  }

  cout << max_length;
}