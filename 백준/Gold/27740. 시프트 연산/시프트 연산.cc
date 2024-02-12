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

const int INF = 999999999;
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
pair<pii, int> calcL(int i) {
  if(i == a.size() - 1) return {{INF, INF}, 1};

  int left = a[i]; // 먼저 왼쪽으로 밀어서 제거
  
  int nextPoint = a[i + 1] - left; // 바로 오른쪽 1의 위치

  // 얘를 오른쪽으로 밀어서 제거
  int right = N - nextPoint + 1;

  return {{left, right}, 1};
}


// 오른쪽 밀고 왼쪽
pair<pii, int> calcR(int i) {
  if(i == 0) return {{INF, INF}, 1};
  
  int right = N - a[i] + 1; // 오른쪽으로 밀어서 제거
  
  int nextPoint = a[i - 1] + right; // 바로 왼쪽 1의 위치

  // 얘를 왼쪽으로 밀어서 제거
  int left = nextPoint;

  return {{left, right}, -1};
}

// 왼 -> 오 or 오 -> 왼이 최선
void solve() {
  int ans = INF;
  pii ansLen = {0, 0};
  int dir = 0; // 1은 L먼저 -1은 R먼저
  
  for(int i = 0; i < a.size(); i++) {
    auto curL = calcL(i);
    if(curL.X.X + curL.X.Y < ans) {
      ans = curL.X.X + curL.X.Y;
      ansLen = {curL.X.X, curL.X.Y};
      dir = curL.Y;
    }
    auto curR = calcR(i);
    if(curR.X.X + curR.X.Y < ans) {
      ans = curR.X.X + curR.X.Y;
      ansLen = {curR.X.X, curR.X.Y};
      dir = curR.Y;
    }
  }

  // L또는 R만 하는 경우
  if(ans > a.back()) {
    ans = a.back();
    ansLen = {a.back(), 0};
    dir = 1;
  }
  if(ans > N - a.front() + 1) {
    ans = N - a.front() + 1;
    ansLen = {0, N - a.front() + 1};
    dir = -1;
  }

  cout << ans << '\n';
  if(dir == 1) {
    for(int i = 0; i < ansLen.X; i++) cout << 'L';
    for(int i = 0; i < ansLen.Y; i++) cout << 'R';
  }
  else {
    for(int i = 0; i < ansLen.Y; i++) cout << 'R';
    for(int i = 0; i < ansLen.X; i++) cout << 'L';
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
