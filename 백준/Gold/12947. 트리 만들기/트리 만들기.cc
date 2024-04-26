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

int N;
int cnt[55];


void input() {
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> cnt[i];
}

void solve() {
  int res = 0;
  int limit = 0;
  for(int i = 1; i <= N; i++) {
    res++;
    if(cnt[i] == 1) {
      res = max(res, limit + 1);
      limit = 0;
    }
    else limit += 2;
  }

  cout << max(res, limit);
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
