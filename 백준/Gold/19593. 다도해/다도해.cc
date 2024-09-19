#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX_N 50001

ll N, E, seed, A, B;
ll p[1005];
set<int> s;

int find(int x) {
  if (p[x] == x)
    return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x > y) p[x] = y;
  else p[y] = x;
}

void solve() {
  cin >> N >> seed >> A >> B;

  // init
  for (int i = 0; i < N; i++) {
    p[i] = i;
  }
  s.clear();

  // E[1] 처리
  E = seed % (N * N);
  s.insert(E);
  ll X = E / N;
  ll Y = E % N;
  int edgeNum = 0;
  if (X != Y) {
    if (find(X) != find(Y)) {
      merge(X, Y);
      edgeNum = 1;
    }
  }
  int numComponents = N - edgeNum;
  int M = 1;

  if (numComponents == 1) {
    cout << M << '\n';
    return;
  }

  while (true) {
    E = (E * A + B) % (N * N);
    M++;
    if (s.find(E) != s.end()) {
      break;
    }
    s.insert(E);
    X = E / N;
    Y = E % N;
    if (X == Y)
      continue;
    if (find(X) != find(Y)) {
      merge(X, Y);
      edgeNum++;
      numComponents--;
      if (numComponents == 1) {
        cout << M << '\n';
        return;
      }
    }
  }
  cout << "0\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc;
  cin >> Tc;
  while (Tc--) {
    solve();
  }

  return 0;
}