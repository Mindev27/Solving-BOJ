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

int N, K;

void input() {
  cin >> N >> K;
}

// 짝수, 홀수 그룹으로 분할
void printEdges() {
  int cnt = 0;
  for(int i = 1; i <= N; i += 2) {
    for(int j = 2; j <= N; j += 2) {
      cout << i << ' ' << j << '\n';
      cnt++;
      if(cnt >= K) return;
    }
  }
}

 void solve() {
  if(N % 2 == 0) { // 짝수
    if(K <= N/2*N/2) {
      cout << "YES\n";
      printEdges();
    }
    else cout << "NO\n";
  }
  else { // 홀수
    if(K <= N/2*(N/2 + 1)) {
      cout << "YES\n";
      printEdges();
    }
    else cout << "NO\n";
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
