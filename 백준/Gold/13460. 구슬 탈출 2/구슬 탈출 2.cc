#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define ll long long

using namespace std;

struct Pos{
  int x, y;
};

int N, M;      // 보드의 크기
Pos r, b, fin; // 붉은색 파란색 공, 목적지 좌표
char board[15][15] = {};
bool visited[15][15][15][15] = {}; // [r.x][r.y][b.x][b.y] 방문여부

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    string temp;
    cin >> temp;
    for(int j = 0; j < M; j++){
      board[i][j] = temp[j];

      if(temp[j] == 'R'){  // 붉은 공
        r.x = i; r.y = j;
        board[i][j] = '.';
      }
      else if(temp[j] == 'B'){  // 파란 공
        b.x = i; b.y = j;
        board[i][j] = '.';
      }
      else if(temp[j] == 'O'){   // 목적지
        fin.x = i; fin.y = j;
      }
    }
  }
}

pair<Pos, Pos> pushBalls(Pos curR, Pos curB, int dx, int dy) {
  // 빨간공 움직이기
  int rDist = 0;
  while(true){
    curR.x += dx; curR.y += dy;
    rDist++;
    if(board[curR.x][curR.y] == 'O') // 목적지 도달
      break;
    if(board[curR.x][curR.y] == '#'){  // 벽 도달
      curR.x -= dx; curR.y -= dy;      // 벽 이전으로 옮기기
      rDist--;
      break;
    }
  }

  // 파란공 움직이기
  int bDist = 0;
  while(true){
    curB.x += dx; curB.y += dy;
    bDist++;
    if(board[curB.x][curB.y] == 'O') // 목적지 도달
      break;
    if(board[curB.x][curB.y] == '#'){  // 벽 도달
      curB.x -= dx; curB.y -= dy;      // 벽 이전으로 옮기기
      bDist--;
      break;
    }
  }

  // 둘이 같은 위치고, 목적지가 아니라면 이동거리가 큰 공을 뒤로
  if(curR.x == curB.x && curR.y == curB.y && board[curR.x][curR.y] != 'O'){
    if(rDist < bDist){
      curB.x -= dx; curB.y -= dy;
    }
    else{
      curR.x -= dx; curR.y -= dy;
    }
  }
  return {curR, curB};
}

void solve() {
  queue<tuple<Pos, Pos, int>> q; // 빨강공 좌표, 파랑공 좌표, 단계
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  q.push(make_tuple(r, b, 0));
  visited[r.x][r.y][b.x][b.y] = true;

  while(!q.empty()){
    Pos curR = get<0>(q.front());
    Pos curB = get<1>(q.front());
    int step = get<2>(q.front());
    q.pop();

    if(step == 10) continue;
    
    for(int i = 0; i < 4; i++){
      pair<Pos, Pos> nPos  // 다음 좌표 계산
        = pushBalls(curR, curB, dx[i], dy[i]);

      Pos nextR = nPos.first;  // 다음 빨간공의 좌표
      Pos nextB = nPos.second; // 다음 파랑공의 좌표

      if(visited[nextR.x][nextR.y][nextB.x][nextB.y])
        continue;

      visited[nextR.x][nextR.y][nextB.x][nextB.y] = true;

      if(nextB.x == fin.x && nextB.y == fin.y) // 파란공이 들어가면 실패
        continue;

      if(nextR.x == fin.x && nextR.y == fin.y){ // 빨간공이 들어가면 성공
        cout << step + 1;
        return;
      }
      q.push(make_tuple(nextR, nextB, step + 1));
    }
  }
  cout << -1;
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
