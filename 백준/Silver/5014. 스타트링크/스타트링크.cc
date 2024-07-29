#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int F, S, G, U, D;
bool visited[1000005];

void input() {
  cin >> F >> S >> G >> U >> D;
}

void solve() {
  memset(visited, false, sizeof(visited));
  queue<pii> q;
  q.push({S, 0});
  visited[S] = true;

  while(!q.empty()) {
    int cur = q.front().X;
    int dist = q.front().Y;
    q.pop();

    if(cur == G) {
      cout << dist << '\n';
      return;
    }

    if(cur + U <= F && !visited[cur + U]) {
      visited[cur + U] = true;
      q.push({cur + U, dist + 1});
    }

    if(cur - D >= 1 && !visited[cur - D]) {
      visited[cur - D] = true;
      q.push({cur - D, dist + 1});
    }
  }
  cout << "use the stairs" << endl;
}

int main() {
  //(void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}