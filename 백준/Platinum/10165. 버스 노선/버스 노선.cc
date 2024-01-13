#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct Bus{
  ll s, e, idx;
};

ll N, M, passZeroMax;
vector<Bus> buses;

void input() {
  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    ll a, b; cin >> a >> b;
    // 0을 거쳐가는 경우
    if(a > b){
      passZeroMax = max(passZeroMax, b);
      b += N; // 스위핑이 가능하게 값 변경
    }
    buses.push_back({a, b, i});
  }
}

void solve() {
  // 버스를 시작점이 오름차순 끝점이 내림차순으로 정렬
  sort(buses.begin(), buses.end(), [](Bus a, Bus b) {
    if(a.s == b.s) return a.e > b.e;
    return a.s < b.s;
  });

  vector<Bus> result; // 답을 저장할 벡터

  for(int i = 0; i < buses.size(); i++) {
    Bus cur = buses[i];

    // 원형인 노선이 직선인 노선을 포함
    if(cur.e <= passZeroMax) continue;

    // 비어있으면 넣기
    if(result.empty()) {
      result.push_back(cur);
      continue;
    }

    // 스위핑
    else if(result.back().e < cur.e) {
      result.push_back(cur);
    }
  }

  sort(result.begin(), result.end(), [](Bus a, Bus b) {
    return a.idx < b.idx;
  });

  for(Bus i : result)
    cout << i.idx << ' ';
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
