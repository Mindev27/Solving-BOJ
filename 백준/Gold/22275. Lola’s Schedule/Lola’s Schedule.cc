#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MAX_HOURS = 480;
ll N, X;
vector<pll> act;
ll maxTime = 0;

void input() {
  cin >> N >> X;
  act.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> act[i].X >> act[i].Y;
    act[i].Y += act[i].X;
    maxTime = max(maxTime, act[i].Y);
  }
  
}

void solve() {
  sort(act.begin(), act.end()); 
  
  ll minConflicts = 99999999;
  ll bestTime = 0;

  for (int T = 0; T <= MAX_HOURS; ++T) {
    ll conflicts = 0;
    int i = 0;

    for (int t = T; t <= maxTime; t += X) {
      while (i < N && act[i].Y < t) i++;
      if(i >= N) break;
      
      if (act[i].X <= t && t <= act[i].Y) {
        conflicts++;
      }
    }

    if (conflicts < minConflicts) {
      minConflicts = conflicts;
      bestTime = T;
    }
  }

  cout << bestTime << " " << minConflicts;
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
