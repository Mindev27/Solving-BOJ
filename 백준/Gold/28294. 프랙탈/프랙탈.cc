#include <iostream>

using namespace std;

const int mod = 1000000007;

long long int power(long long int base, long long int exponent) {
  if(exponent == 0)
    return 1;
  else if(exponent == 1)
    return base;
  
  long long int half = power(base, exponent / 2) % mod;
  long long int result = (half * half) % mod;

  if (exponent % 2 == 1) {
    result = (result * base) % mod;
  }

  return result;
}

int main() {
  int n, a;
  cin >> n >> a;

  long long int length = power(n, a + 1);

  length = (mod + length + power(n - 1, a - 1) - power(n - 1, a + 1)) % mod;
  length = (length * (n-1)) % mod;

  cout << length;
}