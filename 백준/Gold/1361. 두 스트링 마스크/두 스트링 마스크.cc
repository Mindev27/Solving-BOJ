#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

// s1앞, s1뒤, s2앞, s2뒤
string s1f, s1b, s2f, s2b;

void input() {
  string S1, S2;
  cin >> S1 >> S2;

  int bp1 = S1.find('*');
  s1f = S1.substr(0, bp1);    // * 이전 부분
  s1b = S1.substr(bp1 + 1);   // * 이후 부분

  int bp2 = S2.find('*');
  s2f = S2.substr(0, bp2);    // * 이전 부분
  s2b = S2.substr(bp2 + 1);   // * 이후 부분
}

void solve() {
  // *이 없는 문자열
  string s1 = s1f + s1b;
  string s2 = s2f + s2b;

  vector<string> a; // s1로 만들수있는 문자열
  vector<string> b; // s2로 만들수있는 문자열

  // s2에서 i ~ j까지의 문자열을 s1의 *에 넣을때 만들어지는 문자열 찾기
  for(int i = 0; i < s2.size(); i++) {
    for(int j = i; j < s2.size(); j++) {
      string sub = s2.substr(i, j - i + 1);
      a.push_back(s1f + sub + s1b);
    }
  }
  a.push_back(s1); // *에 공백도 넣을 수 있음

  // s1에서 i ~ j까지의 문자열을 s2의 *에 넣을때 만들어지는 문자열 찾기
  for(int i = 0; i < s1.size(); i++) {
    for(int j = i; j < s1.size(); j++) {
      string sub = s1.substr(i, j - i + 1);
      b.push_back(s2f + sub + s2b);
    }
  }
  b.push_back(s2); // *에 공백도 넣을 수 있음
  
  // a, b에서 같은것중 가장 길이가 짧은것 찾기
  int minLen = 9999;
  string ans = "";
  for(string x : a) {
    for(string y : b) {
      if(x == y && minLen > x.size()) {
        minLen = x.size();
        ans = x;
      }
    }
  }

  if(minLen == 9999) cout << "-1";
  else cout << ans;
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
