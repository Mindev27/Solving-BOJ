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
int hp[3];
int d[3] = {9, 3, 1};

void input() {
  cin >> N;
  for(int i = 0; i < N; i++)
    cin >> hp[i];
}

void solve() {
  if(N == 1) {
    cout << ((hp[0] % 9 == 0) ? (hp[0]/9) : (hp[0]/9 + 1));
    return;
  }
  else if(N == 2) {
    pair<pii, int> start = {{hp[0], hp[1]}, 0};
    bool visited[65][65];
    memset(visited, false, sizeof(visited));
    queue<pair<pii, int>> q;
    q.push(start);
    
    while(!q.empty()) {
      int x = q.front().X.X;
      int y = q.front().X.Y;
      int cnt = q.front().Y;
      q.pop();

      if(x <= 0 && y <= 0) {
        cout << cnt;
        return;
      }
      

      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
          if(i == j)
            continue;

          int nx = (x - d[i] > 0) ? (x - d[i]) : 0;
          int ny = (y - d[j] > 0) ? (y - d[j]) : 0;
          if(visited[nx][ny])
            continue;
          
          visited[nx][ny] = true;
          q.push({{nx, ny}, cnt + 1});
        }
      }
    }

  }
  else { // N == 3
    pair<pii, pii> start = {{hp[0], hp[1]}, {hp[2], 0}};
    bool visited[65][65][65];
    memset(visited, false, sizeof(visited));
    queue<pair<pii, pii>> q;
    q.push(start);

    while(!q.empty()) {
      int x = q.front().X.X;
      int y = q.front().X.Y;
      int z = q.front().Y.X;
      int cnt = q.front().Y.Y;
      q.pop();

      if(x <= 0 && y <= 0 && z <= 0) {
        cout << cnt; return;
      }

      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          for(int k = 0; k < 3; k++) {
            if(i == j || j == k || i == k)
              continue;

            int nx = (x - d[i] > 0) ? (x - d[i]) : 0;
            int ny = (y - d[j] > 0) ? (y - d[j]) : 0;
            int nz = (z - d[k] > 0) ? (z - d[k]) : 0;

            if(visited[nx][ny][nz])
              continue;

            visited[nx][ny][nz] = true;
            q.push({{nx, ny}, {nz, cnt + 1}});
          }
        }
      }
    }
  }
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
