#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

string X;
set<string> s;

void input() {
  cin >> X;
}

void solve() {
  for(int i = 0; i < X.length(); i++) {
    for(int j = i; j < X.length(); j++) {
      s.insert(X.substr(i, j - i + 1));
    }
  }
  cout << s.size();
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
