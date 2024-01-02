#include <iostream>
#include <queue>

using namespace std;

const int SIZE =1001;
bool visited[SIZE] = {false};
queue<int> BFSqueue;
int n, m, start;

void DFS(int v, int **map){
  if (visited[v]) return; // 방문했으면 종료
  visited[v] = true; // 방문했음을 표시

  cout << v << ' ';

  for(int i = 1; i <= n; i++){
    if(map[v][i] == 1 && !visited[i]){
      DFS(i,map);
    }
  }
}

void BFS(int v, int **map){
  int current = v;
  
  BFSqueue.push(v);
  visited[v] = true;
  
  while(!BFSqueue.empty()){ // queue가 빌때까지 반복

    current = BFSqueue.front(); // queue의 가장위를 pop
    cout << current << ' ';
    BFSqueue.pop();

    for(int i = 1; i <= n; i++){
      if(map[current][i] == 1 && !visited[i]){ // 연결되어 있고, 방문하지 않았다면
        BFSqueue.push(i); // 큐에 push
        visited[i] = true; // 방문함을 표시
      }
    }
  }
}

int main() {
  int pointX, pointY;

  cin >> n >> m >> start;

  //2차원 배열 동적 할당
  int **map = new int*[n + 1];
  for(int i = 0; i < n + 1; i++){
    map[i] = new int[n + 1]();
  }
  
  // 양방향 간선 정보 저장
  for(int i = 0; i < m; i++){ 
    cin >> pointX >> pointY;
    map[pointX][pointY] = 1;
    map[pointY][pointX] = 1;
  }

  DFS(start, map); // DFS 실행

  //visited를 false로 초기화
  for(int i = 1; i <= 1000; i++){
    visited[i] = false;
  }

  cout << "\n";

  BFS(start, map); // BFS 실행
}