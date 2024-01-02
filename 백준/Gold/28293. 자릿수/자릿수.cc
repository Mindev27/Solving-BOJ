#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  double result = b * log10(a) + 1;
  cout << (int)result;
}