#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, result = 0;
vector<pair<int, int>> downCows; // 내려가는게 빠른 소들
vector<pair<int, int>> upCows;   // 올라가는게 빠른 소들

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    result += a;
    if (a <= b)
      upCows.push_back({a, b});
    else
      downCows.push_back({a, b});
  }
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}

void solve() {
  sort(upCows.begin(), upCows.end()); // U를 기준으로 오름차순
  sort(downCows.begin(), downCows.end(), compare); // D를 기준으로 내림차순

  int time = 0;
  for (int i = 0; i < upCows.size(); i++) {
    if (time <= upCows[i].first)
      time = upCows[i].second;
    else
      time += upCows[i].second - upCows[i].first;
  }

  for (int i = 0; i < downCows.size(); i++) {
    if (time <= downCows[i].first)
      time = downCows[i].second;
    else
      time += downCows[i].second - downCows[i].first;
  }

  cout << result + time;
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
