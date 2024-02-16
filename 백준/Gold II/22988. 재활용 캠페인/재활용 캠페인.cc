#include <algorithm>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, X, perfect = 0;
vector<ll> ml;

void input() {
  cin >> N >> X;
  for(int i = 0 ; i < N; i++) {
    ll a; cin >> a;
    if(a == X) perfect++;
    else ml.push_back(a);
  }
}

void solve() {
  sort(ml.begin(), ml.end());

  int cnt = 0;
  int i = 0, j = ml.size() - 1;

  while(i < j) {
    while(i < j && ml[i] + ml[j] < (X + 1) / 2)
      i++;
    if(i >= j) break;
    cnt++;
    i++; j--;
  }

  // 2번이상 합치면 무조건 가득찬다
  ll answer = perfect + cnt + (ml.size() - cnt * 2) / 3;
  cout << answer;
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
