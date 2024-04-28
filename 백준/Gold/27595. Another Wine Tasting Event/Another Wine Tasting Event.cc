#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

ll N;
string wine;

void input() {
  cin >> N;
  cin >> wine;
}

void solve() {
  ll W = 0;
  for(int i = 0; i < N; i++)
    if(wine[i] == 'W') W++;

  ll maxW = W;
  for(int i = N; i < 2 * N - 1; i++) {
    if(wine[i] == 'W') W++;
    if(wine[i - N] == 'W') W--;
    maxW = max(maxW, W);
  }

  cout << maxW;
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
