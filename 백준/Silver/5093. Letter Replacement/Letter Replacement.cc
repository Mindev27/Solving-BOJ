#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

string s;
char key[5] = {'*', '?', '/', '+', '!'};

void solve() {
  int idx = 0;
  int alpha[30];
  memset(alpha, -1, sizeof(alpha));
  
  for(int i = 0; i < s.size(); i++) {
    char cur = s[i];
    if(cur >= 65 && cur <= 90) cur += 32;
    char out = s[i];
    
    for(int j = 0 ; j < i; j++) {
      char pre = s[j];
      if(pre >= 65 && pre <= 90) pre += 32;
      if(cur == pre) {
        if(alpha[cur - 'a'] == -1) 
          alpha[cur - 'a'] = idx++;
        out = key[alpha[cur - 'a']];
        break;
      }
    }
    cout << out;
  }
  cout << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(cin >> s) {
    if(s == "#") break;
    solve();
  }

  return 0;
}
