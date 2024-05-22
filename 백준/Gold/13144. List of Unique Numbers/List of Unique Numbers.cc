#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
int order[100005];
map<int, int> m;

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    cin >> order[i];
  }
}

void solve() {
  int s = 0, e = 0;
  m[order[0]] = 1;

  ll result = 0;
  while(true) {
    while(e < N - 1 && m[order[e + 1]] == 0) {
      e++; m[order[e]]++;
    }
    if(e == N || s == N) break;

    result += e - s + 1;
    m[order[s]]--; s++;
  }

  cout << result;
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
