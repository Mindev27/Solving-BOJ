#include <iostream>

using namespace std;

int f[41] = {0,};
int fibonacci(int n);

int main() {
  int n;
  cin >> n;

  cout << fibonacci(n) << ' ' << n - 2;
}

int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++){
      f[i] = f[i - 1] + f[i - 2];
    }
        
    return f[n];
}