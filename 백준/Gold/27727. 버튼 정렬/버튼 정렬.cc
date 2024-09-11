#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

ll N;
vector<ll> v, sortedV;
ll K, result = 0;

void solve() {
  cin >> N;
  v.resize(N);
  sortedV.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i];
    sortedV[i] = v[i];
  }
  cin >> K;

  if(N == 1) {
    cout << K;
    return;
  }

  // 정렬하고 처음으로 달라지는 값 비교
  ll p = -1;
  sort(sortedV.begin(), sortedV.end());
  for(int i = N - 1; i >= 0; i--) {
    if(v[i] != sortedV[i]) {
      p = sortedV[i];
      break;
    }
  }

  // 정렬 안됐으면 오름차순으로 고치기
  ll need = 0;
  if(p != -1) {
    for(int i = 0; i < N; i++) {
      if(p - v[i] > 0) need += p - v[i];
    }
  }

  if(need != 0) {
    if(need > K) {
      cout << result; return;
    }
    result += 1;
    K -= need;
  }

  for(int i = 0; i < N; i++){
    if(sortedV[i] < p) sortedV[i] = p;
  }

  // 수열 : 오름차순

  for(ll i = 1; i < N; i++) {
    // i과 i - 1을 비교
    if(sortedV[i] != sortedV[i - 1]) {
      ll need = (sortedV[i] - sortedV[i - 1]) * i;
      if(need > K) {
        cout << result; return;
      }
      result += sortedV[i] - sortedV[i - 1];
      K -= need;
    }
  }

  // max max ... max
  result += K / N;
  cout << result << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}

