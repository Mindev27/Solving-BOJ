#include <iostream>

using namespace std;

int n;
int arr[105] = {};

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}

void solve() {
  long long result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      result += GCD(arr[i], arr[j]);
    }
  }

  cout << result << '\n';
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    input();
    solve();
  }

  return 0;
}
