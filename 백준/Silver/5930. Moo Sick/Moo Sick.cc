#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, C;
vector<int> v;
vector<int> key;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    v.push_back(a);
  }
  cin >> C;
  for(int i = 0; i < C; i++) {
    int a; cin >> a;
    key.push_back(a);
  }
}

void solve() {
  sort(key.begin(), key.end());
  
  vector<int> ans;
  for(int i = 0; i < v.size() - C + 1; i++) {
    vector<int> temp;
    for(int j = i; j < i + C; j++)
      temp.push_back(v[j]);
    sort(temp.begin(), temp.end());

    bool flag = true;
    int gap = temp[0] - key[0];
    for(int i = 0; i < C; i++) {
      if(temp[i] - key[i] != gap) {
        flag = false;
        break;
      }
    }

    if(flag) ans.push_back(i + 1);
  }

  cout << ans.size() << '\n';
  for(int &i : ans)
    cout << i << '\n';
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