#include <algorithm>
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

struct cmp {
  bool operator()(pii a, pii b) {
    if(a.X == b.X) return a.Y < b.Y;
    else return a.X < b.X;
  }
};

// 숫자, 인덱스
priority_queue<pii, vector<pii>, greater<pii>> pq;
int N;

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    int x; cin >> x;
    pq.push({x, i});
  }
}

void solve() {
  bool isSorted = true;
  int result = 1;
  int index = 0;
  
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    isSorted &= (cur.Y == index);
    
    if(cur.Y > index)
      result = max(result, cur.Y - index);

    index++;
  }

  if(isSorted) cout << 1;
  else cout << result + 1;
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