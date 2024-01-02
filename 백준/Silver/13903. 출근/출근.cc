#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 99999999;
int row, col;
bool board[1005][1005] = {};
bool visited[1005][1005] = {};
queue<pair<int, pair<int, int>>> q;
vector<int> dx;
vector<int> dy;

void input() {
  cin >> row >> col;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cin >> board[i][j];
    }
  }
  
  int moveNum; cin >> moveNum;
  while(moveNum--){
    int a, b;
    cin >> a >> b;
    dx.push_back(a);
    dy.push_back(b);
  }
}

int BFS() {
  int result = INF;

  while(!q.empty()) {
    int dist = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    if(x == row - 1){
      result = min(result, dist);
      continue;
    }
    
    for(int i = 0; i < dx.size(); i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= row || ny < 0 || ny >= col)
        continue;
      if(visited[nx][ny] || board[nx][ny] == 0)
        continue;

      q.push({dist + 1, {nx, ny}});
      visited[nx][ny] = true;
    }
  }
  
  return result;
}

void solve() {
  for(int j = 0; j < col; j++){
    if(board[0][j] == 1){
      q.push({0, {0, j}});
      visited[0][j] = true;
    }
  }

  int result = BFS();
  
  if(result == INF)
    cout << "-1";
  else cout << result;
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
