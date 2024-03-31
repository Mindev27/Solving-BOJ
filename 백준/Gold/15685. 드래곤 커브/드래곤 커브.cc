#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
bool v[105][105];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void makeDragon(int a, int b, int dir, int gen) {
  v[a][b] = true;
  int x = a + dx[dir];
  int y = b + dy[dir];
  v[x][y] = true;

  vector<int> dragon;
  dragon.push_back(dir);

  while(gen--) {
    int sz = dragon.size();
    for(int i = sz - 1; i >= 0; i--) {
      int curDir = dragon[i];
      int nextDir = (curDir + 1) % 4;

      x = x + dx[nextDir];
      y = y + dy[nextDir];

      v[x][y] = true;

      dragon.push_back(nextDir);
    }
  }
}

void input() {
  memset(v, false, sizeof(v));
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> b >> a >> c >> d; // 좌표 바꿔서 입력
    makeDragon(a, b, c, d);
  }
}

void solve() {
  int ans = 0;
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(v[i][j] && v[i+1][j] && v[i][j+1] && v[i+1][j+1])
        ans++;
    }
  }
  cout << ans;
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