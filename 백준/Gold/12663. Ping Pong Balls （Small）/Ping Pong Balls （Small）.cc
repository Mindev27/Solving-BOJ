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

int N, M;
pii start;
bool visited[105][105];
int dx[2], dy[2];

void input() {
  cin >> M >> N;
  for (int i = 0; i < 2; i++) {
    cin >> dy[i] >> dx[i];
  }
  cin >> start.Y >> start.X;
}

int solve(int a, int b) {
  queue<pii> q;
  int cnt = 1;
  visited[a][b] = true;
  q.push({a, b});

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    for (int i = 0; i < 2; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;

      if(visited[nx][ny]) continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
      cnt++;
    }
  }

  return cnt;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  for(int t = 1; t <= Tc; t++) {
    memset(visited, false, sizeof(visited));
    input();
    cout << "Case #" << t << ": ";
    cout << solve(start.X, start.Y) << '\n';
    
  }

  return 0;
}
