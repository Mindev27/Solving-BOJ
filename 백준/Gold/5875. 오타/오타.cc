#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

string s;
int leftPrefix[100005];
int rightPrefix[100005];

void input() {
  cin >> s;
}

void solve() {
  int n = s.size();
  int sum;

  sum = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '(') sum += 1;
    else sum -= 1;
    rightPrefix[i] = sum;
  }

  sum = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') sum += 1;
    else sum -= 1;
    leftPrefix[i] = sum;
  }

  if(sum == 2) { // ( 가 더 많음
    int result = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(s[i] == '(') result++;
      if(rightPrefix[i] == 1) { cout << result; return; }
    }
  }
  else if(sum == -2) { // ) 가 더 많음
    int result = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == ')') result++;
      if(leftPrefix[i] == -1) { cout << result; return; }
    }
  }

  cout << 0;
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
