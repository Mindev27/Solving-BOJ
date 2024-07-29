#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int K;

void input() {
  cin >> K;
}

void solve() {
  if(K == 2) {
    cout << "4\n";
    cout << "1 2 1\n";
    cout << "1 4 2\n";
    cout << "3 4 3\n";

    cout << "2 3 4\n";
    cout << "1 3 5\n";
    cout << "2 4 6\n";
    return;
  }

  int N = 4;
  for(int k = 3; k < K; k++) {
    N = N * 2 - 1;
  }
  cout << N << '\n';

  for(int k = 3; k < K; k++) {
    int w = k * 10000;
    N = (N + 1) / 2;
    for(int i = 1; i < N; i++) {
      cout << N + i << ' ' << i << ' ' << ++w << '\n';
    }
  }
  cout << "2 1 9999995\n";
  cout << "1 4 9999997\n";
  cout << "3 4 10000000\n";

  N = 4;
  for(int k = 3; k < K; k++) {
    N = N * 2 - 1;
  }
  for(int k = 3; k < K; k++) {
    int w = (k+1) * 10000;
    N = (N + 1) / 2;
    for(int i = 1; i < N; i++) {
      cout << N + i << ' ' << i + 1 << ' ' << --w << '\n';
    }
  }
  cout << "1 3 9999996\n";
  cout << "2 3 9999998\n";
  cout << "2 4 9999999\n";

}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}