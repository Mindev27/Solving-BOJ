#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

string a, b;

void input() {
  cin >> a >> b;
}

void solve() {
  int aNum = 0, bNum = 0;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == '1') aNum++;
  }
  for(int i = 0; i < b.size(); i++) {
    if(b[i] == '1') bNum++;
  }

  if(aNum % 2 == 1) aNum++;

  if(aNum >= bNum) cout << "VICTORY";
  else cout << "DEFEAT";
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
