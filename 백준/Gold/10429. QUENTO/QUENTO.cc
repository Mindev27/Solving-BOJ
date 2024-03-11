#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char board[5][5];
bool isFind = false;
bool visited[5][5] = {};
string ansPath = "";
char str[3][3] = {
  {'0', '1', '2'},
  {'3', '4', '5'},
  {'6', '7', '8'}
};

void input() {
  cin >> N >> M;
  for(int i = 0; i < 3; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < 3; j++) {
      board[i][j] = temp[j];
    }
  }
}

int calc (string x) {
  int result = board[(x[0] - '0') / 3][(x[0] - '0') % 3] - '0';
  char op;
  for(int i = 1; i < x.size(); i++) {
    pii cur = {(x[i] - '0') / 3, (x[i] - '0') % 3};
    char curStr = board[cur.X][cur.Y];
    if(curStr == '+') op = '+';
    else if(curStr == '-') op = '-';
    else { // 숫자
      if(op == '+') result += curStr - '0';
      else result -= curStr - '0';
    }
  }

  return result;
}

void DFS(pii pos, string path) {
  if(isFind) return;
  
  if(path.length() == 2 * M - 1) {
    if(calc(path) == N) {
      isFind = true;
      ansPath = path;
    }
    return;
  }
  
  for(int i = 0; i < 4; i++) {
    pii next = {pos.X + dx[i], pos.Y + dy[i]};

    if(next.X < 0 || next.X >= 3 || next.Y < 0 || next.Y >= 3)
      continue;

    if(visited[next.X][next.Y]) continue;

    visited[next.X][next.Y] = true;
    path += str[next.X][next.Y];
    DFS(next,  path);
    path.pop_back();
    visited[next.X][next.Y] = false;
  }
}

void solve() {
  visited[0][0] = true; DFS({0, 0} , "0"); visited[0][0] = false;
  visited[0][2] = true; DFS({0, 2} , "2"); visited[0][2] = false;
  visited[1][1] = true; DFS({1, 1} , "4"); visited[1][1] = false; 
  visited[2][0] = true; DFS({2, 0} , "6"); visited[2][0] = false; 
  visited[2][2] = true; DFS({2, 2} , "8"); visited[2][2] = false; 

  if(isFind) {
    cout << "1\n";
    for(char &i : ansPath) {
      cout << (i - '0') / 3 << ' ' << (i - '0') % 3 << '\n';
    }
  }
  else cout << "0";
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}