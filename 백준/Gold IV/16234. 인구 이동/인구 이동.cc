#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, L, R;
int board[55][55];
int visited[55][55];
vector<int> population; // 각 연합의 인구수
vector<vector<pii>> unionPos; // 각 연합의 위치


void input() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

int BFS(int a, int b, int color) {
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  queue<pii> q;

  int num = 0; // 연합의 인구수
  vector<pii> pos; // 연합의 위치
  
  q.push({a, b});
  visited[a][b] = color;

  while(!q.empty()) {
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();

    num += board[x][y];
    pos.push_back({x, y});

    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] != 0)
        continue;

      int gap = abs(board[x][y] - board[nx][ny]);
      if(L <= gap && gap <= R) {
        q.push({nx, ny});
        visited[nx][ny] = color;
      }
    }
  }

  unionPos.push_back(pos);
  return num;
}

bool moving() {
  bool moved = false;
  for(int i = 0; i < population.size(); i++) {
    int next = population[i] / unionPos[i].size();
    for(pii &p : unionPos[i]) {
      if(board[p.X][p.Y] != next) { // 인구 이동이 발생하는 경우
        board[p.X][p.Y] = next;
        moved = true; // 인구 이동 플래그 업데이트
      }
    }
  }
  return moved;
}

void solve() {
  int day = 0;
  while(true) {
    memset(visited, 0, sizeof(visited));
    population.clear();
    unionPos.clear();

    int color = 1;
    for(int i = 0; i < N; i++) { // 연합끼리 색칠
      for(int j = 0; j < N; j++) {
        if(!visited[i][j]) {
          population.push_back(BFS(i, j, color));
          color++;
        }
      }
    }
    if(!moving()) break;
    day++;
  }

  cout << day;
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
