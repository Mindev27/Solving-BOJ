#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, player, ans = 0;
int point[20];
int change[20][20];
bool isLive[20];

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> point[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> change[i][j];
    }
  }
  cin >> player;
}

void backTracking(int playerNum, int days) {
  if(playerNum == 1 || isLive[player] == false) {
    ans = max(ans, days);
    return;
  }

  if(playerNum % 2 == 1) { // 낮
    int kill, killPoint = 0;
    for(int i = 0; i < N; i++) {
      if(isLive[i] == false) continue;
      if(killPoint < point[i]) {
        killPoint = point[i];
        kill = i;
      }
    }

    if (kill == player) {
      ans = max(ans, days);
      return;
    }

    isLive[kill] = false;
    backTracking(playerNum - 1, days);
    isLive[kill] = true;
  }
  
  else { // 밤
    for(int i = 0; i < N; i++) {
      if(isLive[i] == false) continue;
      if(i == player) continue;

      isLive[i] = false; // i번째를 죽이기
      for(int j = 0; j < N; j++) {
        if(isLive[j]) point[j] += change[i][j];
      }
      
      backTracking(playerNum - 1, days + 1);

      for(int j = 0; j < N; j++) {
        if(isLive[j]) point[j] -= change[i][j];
      }
      isLive[i] = true;
    }
  }
}

void solve() {
  for(int i = 0; i < N; i++)
    isLive[i] = true;
  backTracking(N, 0);
  cout << ans;
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