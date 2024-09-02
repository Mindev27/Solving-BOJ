#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
int board[1005][1005];

void solve() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string s; cin >> s;
    for(int j = 0; j <  M; j++) {
      board[i][j] = s[j] - '0';
    }
  }

  // 개수 세기
  int oddRow = 0, oddCol = 0;
  for(int i = 0; i < N; i++) {
    int cnt = 0;
    for(int j = 0; j < M; j++) {
      if(board[i][j]) cnt++;
    }
    oddRow += cnt % 2 == 1;
  }

  for(int j = 0; j < M; j++) {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
      if(board[i][j]) cnt++;
    }
    oddCol += cnt % 2 == 1;
  }

  int result = INT_MAX, ans;
  int a = oddRow, b = oddCol;
  // 가로를 모두 홀로 통일 -> 세로를 홀수번 바꾸기
  ans = N - oddRow;
  if(ans % 2 == 1) oddCol = M - oddCol;

  if(oddCol % 2 == 0) ans = INT_MAX;
  else ans += oddCol;

  result = min(result, ans);

  // 가로를 모두 짝으로 통일 -> 세로를 짝수번 바꾸기
  oddRow = a, oddCol = b;
  ans = oddRow;
  if(ans % 2 == 1) oddCol = M - oddCol;

  if(oddCol % 2 == 1) ans = INT_MAX;
  else ans += oddCol;

  result = min(result, ans);

  // 세로를 모두 홀로 통일 -> 가로를 홀수번 바꾸기
  oddRow = a, oddCol = b;
  ans = M - oddCol;
  if(ans % 2 == 1) oddRow = N - oddRow;

  if(oddRow % 2 == 0) ans = INT_MAX;
  else ans += oddRow;

  result = min(result, ans);

  // 세로를 모두 짝으로 통일 -> 가로를 짝수번 바꾸기
  oddRow = a, oddCol = b;
  ans = oddCol;
  if(ans % 2 == 1) oddRow = N - oddRow;

  if(oddRow % 2 == 1) ans = INT_MAX;
  else ans += oddRow;

  result = min(result, ans);

  cout << result;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
