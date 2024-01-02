#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
bool visited[25][25] = {};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int,int>> q;

int bfs(int x, int y, int **map);

int main() {
  vector<int> v;
  
  cin >> n;

  int **map = new int*[n];
  for(int i = 0; i < n; i++){
    map[i] = new int[n]();
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%1d", &map[i][j]);
    }
  }
  

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(map[i][j] == 1 && !visited[i][j])
        v.push_back(bfs(i, j, map));
    }
  }

  cout << v.size() << "\n";

  sort(v.begin(), v.end());
  
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << "\n";
  }
  
  delete [] map;
}

int bfs(int x, int y, int **map){
  int cnt = 1;
  visited[x][y] = true;
  q.push(make_pair(x, y));
  
  while(!q.empty()){
    int tempX = q.front().first;
    int tempY = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = tempX + dx[i];
      int ny = tempY + dy[i];

      if(0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] == 1 && !visited[nx][ny]){
        q.push(make_pair(nx, ny));
        cnt++;
        visited[nx][ny] = true;
      }
    }
  }

  return cnt;
}