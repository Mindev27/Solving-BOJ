#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, K;
vector<pii> v;       // 방향, 거리
map<pii, vector<int>> pTime; // 위치별로 씨앗 심은 시간 기록

void input() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    char x; int y;
    cin >> x >> y;
    if(x == 'N') v.push_back({0, y});
    else if(x == 'S') v.push_back({1, y});
    else if(x == 'E') v.push_back({2, y});
    else v.push_back({3, y});
  }
}

// 미리 전처리로 위치 방문 시간 계산
void preprocess() {
  int xPos = 0, yPos = 0;
  int time = 0;

  for (auto &i : v) {
    int dir = i.X;
    int cnt = i.Y;

    for (int j = 0; j < cnt; j++) {
      // 이동
      time++;
      xPos += dx[dir];
      yPos += dy[dir];

      pii pos = {xPos, yPos};
      pTime[pos].push_back(time);
    }
  }
}

bool check(int x) {
  int total = 0;
  for(auto &i : pTime) {
    vector<int> times = i.Y;
    int preTime = times[0];
    
    for(int i = 1; i < times.size(); i++) {
      if(times[i] - preTime >= x) {
        total++;
        preTime = times[i];
      }
    }
  }

  return total >= K;
}

void solve() {
  preprocess();
  
  int lo = 1, hi = 100000000;
  int ans = -1;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) { ans = mid; lo = mid + 1; }
    else { hi = mid - 1; }
  }

  cout << ans << '\n';
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
