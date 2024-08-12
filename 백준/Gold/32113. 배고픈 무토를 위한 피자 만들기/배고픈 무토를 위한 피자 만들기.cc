#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N;
pii start;
char board[55][55];
vector<string> ans;

void input() {
  cin >> N;
  cin >> start.X >> start.Y;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  // 시작지점 기준 행을 모두 채우고 1열 채우기
  for(int i = 0; i < start.Y - 1; i++) {
    ans.push_back("L " + to_string(start.X) + " push");
  }
  for(int i = 0; i < N - start.Y; i++) {
    ans.push_back("R " + to_string(start.X) + " push");
  }

  // 1열 채우기
  for(int i = 0; i < start.X - 1; i++) {
    ans.push_back("U 1 push");
  }
  for(int i = 0; i < N - start.X; i++) {
    ans.push_back("D 1 push");
  }

  // 가운데 기준으로 1행까지 채우면서 똑같이 만들기
  for(int i = start.X - 1; i >= 1; i--) {

    // i 행 채우고
    for(int j = 1; j <= N - 1; j++) {
      ans.push_back("R " + to_string(i) + " push");
    }

    // 맵과 똑같이 만들기
    for(int j = 2; j <= N; j++) {
      if(board[i][j] == '.') {
        ans.push_back("U " + to_string(j) + " pull");
      }
    }
  }

  // 가운데 줄 빼기
  int i = start.X;
  for(int j = 2; j <= N; j++) {
    if(board[i][j] == '.') {
      ans.push_back("D " + to_string(j) + " pull");
    }
  }

  // 밑으로 1행씩 채우고 빼기
  for(int i = start.X + 1; i <= N; i++) {

    // i 행 채우고
    for(int j = 1; j <= N - 1; j++) {
      ans.push_back("R " + to_string(i) + " push");
    }

    // 맵과 똑같이 만들기
    for(int j = 2; j <= N; j++) {
      if(board[i][j] == '.') {
        ans.push_back("D " + to_string(j) + " pull");
      }
    }
  }

  // 1열 맞추기
  int j = 1;
  for(int i = 1; i <= N; i++) {
    if(board[i][j] == '.') {
      ans.push_back("L " + to_string(i) + " pull");
    }
  }

  cout << ans.size() << '\n';
  for(string s : ans) {
    cout << s << '\n';
  }
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
