#include <iostream>
#include <queue>

using namespace std;

int map[50][50] = {};
queue<pair<int, int>> q;
int w, h, blockNum, lampNum = 0;

int BFS();

int main() {
  cin >> w >> h;
  cin >> blockNum;

  for(int i = 0; i < blockNum; i++){
    int x, y;
    string type;
    cin  >> type >> x >> y;
    if(type == "redstone_block"){
      map[x][y] = 16;
      q.push({x, y});
    }
    else if(type == "redstone_lamp"){
      map[x][y] = -1;
      lampNum++;
    }
    else // 가루인 경우
      map[x][y] = 1;

  }

  if(q.empty()) // 블럭이 없다면
    cout << "failed";
  else{
    int count = BFS(); // 켜진 램프개수 세기

    if(count == lampNum)
      cout << "success";
    else
      cout << "failed";
  }
}


//블럭 = 16, 가루 = 1, 램프 = -1
int BFS(){
  int count = 0; // 켜진 램프 수
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0 <= nx && nx < w && 0 <= ny && ny < h){
        if(map[nx][ny] == -1 && map[x][y] >= 2){ // 램프고 전기가 있다면 개수 세기
          map[nx][ny] = 0;
          count++;
        }
        else if(map[nx][ny] != 0){ // 가루거나 블럭이라면 
          if(map[nx][ny] < map[x][y] - 1){ // 옮길때 전기 신호가 커지면 업데이트
            map[nx][ny] = map[x][y] - 1;
            q.push({nx, ny});
          }
        }
      }
    }
  }

  return count;
}