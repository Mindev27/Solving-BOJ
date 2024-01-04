#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct POS {
  int x, y;
};

const int SIZE = 55;
int row, col;
char board[SIZE][SIZE] = {};
bool visited[SIZE][SIZE][SIZE][SIZE]; // 팩맨의 x,y좌표들(2개)
vector<POS> pac; // 팩맨의 위치

void init() {
  memset(visited, false, sizeof(visited));
  pac.clear();
}

void input() {
  cin >> row >> col;
  for(int i = 0; i < row; i++) {
    string a; cin >> a;
    for(int j = 0; j < col; j++) {
      board[i][j] = a[j];
      if(board[i][j] == 'P'){
        pac.push_back({i, j});
        board[i][j] = '.';
      }  
    }
  }
}

string BFS(POS a, POS b) {
  char dc[4] = {'S', 'N', 'E', 'W'};
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  queue<pair<pair<POS, POS>, string>> q;
  string command = "";
  
  q.push({{a, b}, command});
  visited[a.x][a.y][b.x][b.y] = true;

  while(!q.empty()) {
    POS p1 = q.front().first.first;
    POS p2 = q.front().first.second;
    string c = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      POS np1 = {p1.x + dx[i], p1.y + dy[i]};
      POS np2 = {p2.x + dx[i], p2.y + dy[i]};
      string nc = c + dc[i];

      // 벽 넘어가는 로직
      if(np1.x < 0) np1.x = row - 1;
      if(np1.y < 0) np1.y = col - 1;
      if(np2.x < 0) np2.x = row - 1;
      if(np2.y < 0) np2.y = col - 1;
      if(np1.x >= row) np1.x = 0;
      if(np1.y >= col) np1.y = 0;
      if(np2.x >= row) np2.x = 0;
      if(np2.y >= col) np2.y = 0;

      // 다음칸이 유령이면 안됨
      if(board[np1.x][np1.y] == 'G' || board[np2.x][np2.y] == 'G')
        continue;

      // 다음칸이 벽이라면 원래칸으로 되돌리기
      if(board[np1.x][np1.y] == 'X'){
        np1.x = p1.x; np1.y = p1.y;
      }
      if(board[np2.x][np2.y] == 'X'){
        np2.x = p2.x; np2.y = p2.y;
      }

      // 두 팩맨이 만나면 경로반환
      if(np1.x == np2.x && np1.y == np2.y)
        return nc;

      // 지금까지 없던 위치이면 방문표시 후 큐에 넣기
      if(!visited[np1.x][np1.y][np2.x][np2.y]) {
        visited[np1.x][np1.y][np2.x][np2.y] = true;
        q.push({{np1, np2}, nc});
      }
    }
  }

  return "0";
}

void solve() {
  string result = BFS(pac[0], pac[1]); // 경로 받아오기
  if(result == "0")
    cout << "IMPOSSIBLE" << '\n';
  else{
    cout << result.length() << ' ';
    cout << result << '\n';
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while(T--) {
    init();
    input();
    solve();
  }
  
  return 0;
}