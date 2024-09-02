#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  int N, L, K;
  vector<pii> ant; // 위치, ID

  cin >> N >> L >> K;
  for(int i = 0; i < N; i++) {
    int x, ID; cin >> x >> ID;
    ant.push_back({x, ID});

  }

  // 결국 왼쪽 오른쪽만큼 떨어진다.
  // 떨어지는 시간, ID를 계산
  vector<pii> time; // 시간, ID
  for(pii &i : ant) {
    if(i.Y < 0) { // 왼쪽
      time.push_back({i.X, i.Y});
    }
    else { // 오른쪽
      time.push_back({L - i.X, i.Y});
    }
  }

  sort(time.begin(), time.end());

  vector<pii> order; // 떨어지는 ID 순서

  int leftIdx = 0, rightIdx = N - 1;
  for(pii &i : time) { // 하나씩 떨어지는 개수 구하기
    if(i.Y < 0) {
      auto target = ant[leftIdx++];
      order.push_back({target.Y, i.X});
    }
    else {
      auto target = ant[rightIdx--];
      order.push_back({target.Y, i.X});
    }

    if(order.size() >= 2 && order.back().Y == order[order.size() - 2].Y) {
      if(order.back().X < order[order.size() - 2].X) {
        swap(order[order.size() - 2], order[order.size() - 1]);
      }
    }
  }

  cout << order[K - 1].X << "\n";
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    solve();
  }

  return 0;
}
