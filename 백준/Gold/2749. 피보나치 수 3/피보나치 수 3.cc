/* 피사노 주기:
k(m)이 피보나치수를 m으로 나눈 나머지의 주기라고할때
n > 2라면, k(10^n) = 15×10^(n-1)이 성립한다. 즉 주기는 1500000이다.
*/
#include <iostream>

using namespace std;

const int MAX_CYCLE =1500000;
const int DIV       =1000000;

int fibo(int k) {
  int a = 0;
  int b = 1;
  int c;

  for (int i = 2; i <= k; i++) {
    c = (a % DIV + b % DIV) % DIV;
    a = b;
    b = c;
  }

  return c;
}

int main() {
  long long int n;
  int Num, result;

  cin >> n;

  if(n == 1){
    cout << 1;
    return 0;
  }

  Num = n % MAX_CYCLE; // 주기가 1500000이므로

  result = fibo(Num);

  cout << result;
}