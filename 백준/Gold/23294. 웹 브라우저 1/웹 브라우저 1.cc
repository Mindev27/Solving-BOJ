#include <algorithm>
#include <deque>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, Q, C;
vector<int> cache;
vector<pair<char, int>> query;
deque<pii> F, B; // 번호와 캐시

void input() {
  cin >> N >> Q >> C;
  cache.clear();
  cache.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> cache[i];
  }
  for (int i = 0; i < Q; i++) {
    char a; cin >> a;
    if(a == 'A') {
      int b; cin >> b;
      query.push_back({a, b});
    }
    else query.push_back({a, 0});
  }
}

void solve() {
  pii cur = {-1, 0}; // 현재 접속 페이지, 캐시
  int backCache = 0, frontCache = 0;
  
  for (auto &q : query) {
    if(q.X == 'B') {
      if(B.empty()) continue;
      F.push_back(cur);
      frontCache += cur.Y;
      cur = B.back();

      backCache -= B.back().Y;
      B.pop_back();
    }

    else if(q.X == 'F') {
      if(F.empty()) continue;
      B.push_back(cur);

      backCache += cur.Y;
      cur = F.back();
      frontCache -= F.back().Y;
      F.pop_back();
    }

    else if(q.X == 'C') {
      if (B.empty()) continue;
      
      deque<pii> newB;
      int tempCache = 0;
      for (int i = 0; i < B.size() - 1; ++i) {
        if (B[i].X == B[i + 1].X) continue;
        newB.push_back(B[i]);
        tempCache += B[i].Y;
      }
      newB.push_back(B.back());
      tempCache += B.back().Y;
      
      B = newB; backCache = tempCache;
    }

    else{ // A인 경우
      while(!F.empty()) {
        frontCache -= F.back().Y;
        F.pop_back();
      }
      if(cur.X != -1) {
        B.push_back(cur);
        backCache += cur.Y;
      }
      cur = {q.Y,cache[q.Y]};

      while(frontCache + backCache + cur.Y > C){
        backCache -= B.front().Y;
        B.pop_front();
      }
    }
  }

  // 답 출력
  cout << cur.X << '\n';
  if(B.empty()) cout << -1 << '\n';
  else {
    while(!B.empty()) {
      cout << B.back().X << ' ';
      B.pop_back();
    }
    cout << "\n";
  }
  if(F.empty()) cout << -1 << '\n';
  else {
    while(!F.empty()) {
      cout << F.back().X << ' ';
      F.pop_back();
    }
    cout << "\n";
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