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

const int SIZE = 200000;
int N, K;
queue<pair<pii, string>> q;
bool visited[200005];

void input() {
  cin >> N >> K;
}

void printPath(string p) {
  cout << N << ' ';
  int cur = N;
  for(char c : p) {
    if(c == '-') { cur -= 1; cout << cur << ' '; }
    else if(c == '+') { cur += 1; cout << cur << ' '; }
    else { cur *= 2; cout << cur << ' '; }
  }
}

void solve() {
  if(K <= N) {
    cout << N - K << "\n";
    for(int i = N; i >= K; i--) {
      cout << i << " ";
    }
    return;
  }

  string path;
  q.push({{N, 0}, ""});
  visited[N] = true;

  while(!q.empty()) {
    int cur = q.front().X.X;
    int step = q.front().X.Y;
    string s = q.front().Y;
    q.pop();

    if(cur == K) {
      cout << step << '\n';
      printPath(s);
      break;
    }

    if(cur - 1 >= 0 && !visited[cur - 1]) {
      visited[cur - 1] = true;
      q.push({{cur - 1, step + 1}, s + "-"});
    }

    if(cur > K) continue;
    
    if(cur * 2 <= SIZE && !visited[cur * 2]) {
      visited[cur * 2] = true;
      q.push({{cur * 2, step + 1}, s + "*"});
    }
    if(cur + 1 <= SIZE && !visited[cur + 1]) {
      visited[cur + 1] = true;
      q.push({{cur + 1, step + 1}, s + "+"});
    }
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