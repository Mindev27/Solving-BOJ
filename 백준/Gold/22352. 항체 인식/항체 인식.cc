#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, key;
int map1[30][30] = {};
int map2[30][30] = {};
int map[30][30] = {};
bool visited[30][30] = {};
queue<pair<int, int>> q;

int bfs(int i, int j, int key, int map[][30]);

int main() {
  cin >> n >> m;

  //첫 번째 배열 입력
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map1[i][j];
    }
  }

  //두 번째 배열 입력
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map2[i][j];
    }
  }
  
  //배열 비교 후 같으면 0
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(map1[i][j] == map2[i][j]) 
        map[i][j] = 0;
      else
        map[i][j] = map2[i][j];
    }
  }
  
  int startx, starty, tileNum, changedNum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(map[i][j] != 0 && !visited[i][j]){
        startx = i;
        starty = j;
        key = map[i][j];
        tileNum = bfs(i, j, key, map);
        changedNum++;
      }
    }
  }

  memset(visited, false, sizeof(visited));

  if(changedNum >= 2)
    cout << "NO";
  else if(changedNum == 0)
    cout << "YES";
  else{
    key = map1[startx][starty];
    if(tileNum != bfs(startx, starty, key, map1))
      cout << "NO";
    else
      cout << "YES";
  }   
}

int bfs(int i, int j, int key, int map[][30]){
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  int cnt = 1;

  visited[i][j] = true;
  q.push(make_pair(i, j));

  while(!q.empty()){
    int tempX = q.front().first;
    int tempY = q.front().second;
    q.pop();
    
    for(int i = 0; i < 4; i++){
      int nx = tempX + dx[i];
      int ny = tempY + dy[i];

      if(0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == key && !visited[nx][ny]){
        q.push(make_pair(nx, ny));
        cnt++;
        visited[nx][ny] = true;
      }
    }
  }

  return cnt;
}