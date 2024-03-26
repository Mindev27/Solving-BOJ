#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N;
vector<ll> p;
bool allOne = true;
ll temp;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    ll x; cin >> x;
    p.push_back(x);
    if(x != 1) {
      temp = x;
      allOne = false;
    }
  }
}

void solve() {
  if(allOne) {
    cout << ((N % 2 == 0) ? "koosaga" : "cubelover");
    return;
  }

  
  ll grundy = 0;
  int oneSet = 0;
  for(ll &i : p) {
    if(i == 1) oneSet++;
    grundy ^= i;
  }

  if(oneSet == 0) {
    if(grundy) cout << "koosaga";
    else cout << "cubelover";
  }
  else if(oneSet % 2 == 1) {
    if(grundy) cout << "koosaga";
    else cout << "cubelover";
  }
  else {
    grundy ^= temp;
    grundy ^= 1;
    if(grundy) cout << "koosaga";
    else cout << "cubelover";
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