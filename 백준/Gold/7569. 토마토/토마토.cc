#include <iostream>
#include <queue>
#include<tuple>

using namespace std;

int map[100][100][100] = {};
int visited[100][100][100] = {};
int yLim, xLim, zLim, count = 0; // 탐색에서 익게되는 토마토의 수
queue<tuple<int, int, int>> q;

int BFS();

int main() {
  int tomato = 0;
  cin >> yLim >> xLim >> zLim;

  for(int z = 0; z < zLim; z++){
    for(int x = 0; x < xLim; x++){
      for(int y = 0; y < yLim; y++){
        int temp;
        cin >> temp;
        map[x][y][z] = temp;

        if(temp == 1) // 토마토의 위치를 미리 큐에 저장
          q.push({x, y, z});
        
        if(temp == -1) // 없는자리 방문표시
          visited[x][y][z] = true;
        
        if(temp == 0) // 몇개가 익어야하는지 저장
          tomato++; 
      }
    }
  }
  
  //정답 출력
  if(tomato == 0) // 이미 다 익었다면
    cout << 0;
  else{
    int maxDate = BFS(); // 익는데 걸리는 최대 시간
    
    if(count != tomato) // 전부 익지 못했다면
      cout << -1;
    else
      cout << maxDate - 1;
  }
}

//너비우선 탐색
int BFS(){
  int maxDate = 0;
  int dx[6] = {1, -1, 0, 0, 0, 0};
  int dy[6] = {0, 0, 1, -1, 0, 0};
  int dz[6] = {0, 0, 0, 0, 1, -1};

  //입력 때 토마토의 위치를 모두 큐에 넣었음
  while(!q.empty()){
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    int z = get<2>(q.front());
    visited[x][y][z] = true;
    q.pop();
    
    for(int i = 0; i < 6; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      // 범위내인지 확인
      if(0 <= nx && nx < xLim && 0 <= ny 
                && ny < yLim && 0 <= nz && nz < zLim){

        // 토마토가 있고 방문하지 않았다면
        if(map[nx][ny][nz] == 0 && !visited[nx][ny][nz]){
          map[nx][ny][nz] = map[x][y][z] + 1;
          q.push({nx, ny, nz});
          count++;
          maxDate = max(maxDate, map[nx][ny][nz]);
        }
      }
    }
  }
  return maxDate;
}