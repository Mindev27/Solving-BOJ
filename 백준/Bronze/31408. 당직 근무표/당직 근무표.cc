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

int N;
int a[100005];

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    int x; cin >> x;
    a[x]++;
  }
}

void solve() {
  int val = 0;
  for(int i = 1; i <= 100000; i++) {
    val = max(val, a[i]);
  }

  if((N + 1) / 2 >= val){
    cout << "YES";
  }
  else{
    cout << "NO";
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
