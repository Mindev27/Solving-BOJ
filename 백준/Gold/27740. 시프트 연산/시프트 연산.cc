#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 9999999;
int N;
vector<int> a; // 1의 위치를 저장

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    if(x == 1) a.push_back(i);
  }
}

// 왼쪽 밀고 오른쪽
pair<int, string> calcL(int i) {
  if(i == a.size() - 1) return {INF, ""};

  int cnt = a[i]; // 먼저 왼쪽으로 밀어서 제거
  string s = string(a[i], 'L');
  
  int nextPoint = a[i + 1] - cnt; // 바로 오른쪽 1의 위치

  // 얘를 오른쪽으로 밀어서 제거
  cnt += N - nextPoint + 1;
  s += string(N - nextPoint + 1, 'R');

  return {cnt, s};
}


// 오른쪽 밀고 왼쪽
pair<int, string> calcR(int i) {
  if(i == 0) return {INF, ""};
  
  int cnt = N - a[i] + 1; // 오른쪽으로 밀어서 제거
  string s = string(N - a[i] + 1, 'R');
  
  int nextPoint = a[i - 1] + cnt; // 바로 왼쪽 1의 위치

  // 얘를 왼쪽으로 밀어서 제거
  cnt += nextPoint;
  s += string(nextPoint, 'L');

  return {cnt, s};
}

// 왼 -> 오 or 오 -> 왼이 최선
void solve() {
  int ans = INF;
  string result = "";
  for(int i = 0; i < a.size(); i++) {
    auto curL = calcL(i);
    if(curL.X < ans) {
      ans = curL.X;
      result = curL.Y;
    }
    auto curR = calcR(i);
    if(curR.X < ans) {
      ans = curR.X;
      result = curR.Y;
    }
  }

  // L또는 R만 하는 경우
  if(ans > a.back()) {
    ans = a.back();
    result = string(a.back(), 'L');
  }
  if(ans > N - a.front() + 1) {
    ans = N - a.front() + 1;
    result = string(N - a.front() + 1, 'R');
  }

  cout << ans << '\n' << result;
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
