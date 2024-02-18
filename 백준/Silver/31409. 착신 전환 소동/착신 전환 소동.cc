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
int p[100005];

int find(int x) {
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void uni(int a, int b) {
  a = find(a);
  b = find(b);
  if(a > b) p[a] = b;
  else p[b] = a;
}

void input() {
  cin >> N;
  for(int i = 1 ; i <= N; i++) {
    cin >> p[i];
  }
}

void solve() {
  vector<int> solo;
  for(int i = 1; i <= N; i++) {
    if(p[i] == i) solo.push_back(i);
  }

  cout << solo.size() << '\n';
  if(solo.size() == 0);
  else if(solo.size() == 1) {
    if(solo[0] == 1) p[solo[0]] = 2;
    else p[solo[0]] = 1;
  }
  else{
    int temp = solo.back();
    for(int i = 1; i < solo.size(); i++){
      p[solo[i]] = solo[i - 1];
    }
    p[solo[0]] = temp;
  }
  
  for(int i = 1; i <= N; i++)
    cout << p[i] << ' ';
  
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
