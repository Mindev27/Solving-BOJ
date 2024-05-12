#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int MAX = 505;
int N, M;
int p[MAX]; // 음수면 현재까지 비용 양수면 부모루트

int find(int x) {
  if(p[x] == -1) return -1;
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

bool merge(int x, int y) {
  x = find(x), y = find(y);
  if(x == y) {
    p[x] = -1; p[y] = -1;
    return false;
  }

  if(x > y) swap(x, y);
  p[y] = x;
  return true;
}

void solve() {
  // init
  for(int i = 1; i <= N; i++)
    p[i] = i;

  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    merge(a, b);
  }

  int cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(p[i] == -1) continue;
    if(find(p[i]) == i) cnt++;
  }

  if(cnt == 0) cout << "No trees.\n";
  else if(cnt == 1) cout << "There is one tree.\n";
  else cout << "A forest of " << cnt << " trees.\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while(true) {
    cin >> N >> M;
    if(N == 0 && M == 0) break;
    cout << "Case " << t++ << ": ";
    solve();
  }
  

  return 0;
}