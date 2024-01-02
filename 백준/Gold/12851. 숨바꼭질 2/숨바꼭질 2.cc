#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
int cnt, minSecond;
bool visited[MAX] = {};

int BFS(int n, int k);

int main() {
  int n, k;

  cin >> n >> k;

  cout << BFS(n, k) << "\n";
  cout << cnt;
}

int BFS(int n, int k) {
  cnt = minSecond = 0;
  queue<pair<int, int>> q;
  q.push({n, 0});

  visited[n] = true;

  while (!q.empty()) {
    int loc = q.front().first;
    int time = q.front().second;
    q.pop();

    visited[loc] = true;

    if (loc == k && minSecond == 0) {
      minSecond = time;
      cnt = 1;
    } else if (loc == k && minSecond != 0 && minSecond == time) {
      cnt++;
    }

    if (loc + 1 < MAX && !visited[loc + 1])
      q.push({loc + 1, time + 1});
    if (loc - 1 >= 0 && !visited[loc - 1])
      q.push({loc - 1, time + 1});
    if (loc * 2 < MAX && !visited[loc * 2])
      q.push({loc * 2, time + 1});
  }
  return minSecond;
}