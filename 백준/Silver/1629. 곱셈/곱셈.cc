#include <iostream>

using namespace std;

int a, b, c;

long long power(int a, int b) {
  if (b == 1) {
    return a % c;
  }

  long long temp = power(a, b / 2);

  if (b % 2 == 1)
    return ((temp * temp % c) * (a % c)) % c;
  else
    return (temp * temp) % c;
}

int main() {
  // freopen("input.txt", "r", stdin);
  cin >> a >> b >> c;

  cout << power(a, b);
}