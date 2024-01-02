#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int R, C;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<int> parent;

int cnt;
int firstSwan, secondSwan;

int findParent(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = findParent(parent[a]);
}

bool unionParent(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if (a == b)
    return false;
  else if (a < b) {
    parent[b] = a;
  } else {
    parent[a] = b;
  }
  return true;
}

bool bfs(int y, int x) {
  if (visited[y][x] || board[y][x] != 0)
    return false;
  visited[y][x] = true;

  cnt++;

  board[y][x] = cnt;

  queue<pair<int, int>> q;
  q.push({y, x});

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
        continue;
      if (visited[ny][nx])
        continue;
      if (board[ny][nx] == 0) {
        visited[ny][nx] = true;
        board[ny][nx] = cnt;
        q.push({ny, nx});
      }
    }
  }

  return true;
}

int solve() {
  queue<pair<pair<int, int>, int>> q;

  int day = 0;

  if (findParent(firstSwan) == findParent(secondSwan))
    return day;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] != -1) {
        visited[i][j] = true;
        for (int dir = 0; dir < 4; dir++) {
          int ny = i + dy[dir];
          int nx = j + dx[dir];
          if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
          if (!visited[ny][nx] && board[ny][nx] == -1) {
            visited[ny][nx] = true;
            q.push({{ny, nx}, board[i][j]});
          }
        }
      }
    }
  }

  while (!q.empty()) {
    day++;
    int qSize = q.size();
    for (int i = 0; i < qSize; i++) {
      int cy = q.front().first.first;
      int cx = q.front().first.second;
      int cur = q.front().second;
      q.pop();

      board[cy][cx] = cur;

      for (int dir = 0; dir < 4; dir++) {
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
          continue;
        if (visited[ny][nx]) {
          if (board[ny][nx] == -1) {
            continue;
          } else {
            if (findParent(cur) != findParent(board[ny][nx])) {
              unionParent(cur, board[ny][nx]);
            }
          }
        } else {
          visited[ny][nx] = true;
          q.push({{ny, nx}, cur});
        }
      }
    }

    if (findParent(firstSwan) == findParent(secondSwan))
      return day;
  }

  return -1;
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> C;
  board.assign(R, vector<int>(C, -1));
  visited.assign(R, vector<bool>(C, false));

  vector<pair<int, int>> swan;

  char c;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> c;
      if (c == '.') {
        board[i][j] = 0;
      } else if (c == 'L') {
        board[i][j] = 0;
        swan.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      bfs(i, j);
    }
  }

  parent.resize(cnt + 1);
  for (int i = 0; i <= cnt; i++) {
    parent[i] = i;
  }

  firstSwan = board[swan[0].first][swan[0].second];
  secondSwan = board[swan[1].first][swan[1].second];

  visited.assign(R, vector<bool>(C, false));

  cout << solve();

  return 0;
}