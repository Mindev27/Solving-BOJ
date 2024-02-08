#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve(ll N) {
  cout << 1999 << '\n';
  for(int i = 0; i < 999; i++)
    cout << "1 ";
  for(int i = 0; i < 1000; i++)
    cout << "1000 ";
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll N; cin >> N;
  solve(N);

  return 0;
}