#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>

using namespace std;

pair<ll, pss> a_wins(const string &A, const string &B, int i = -1) {
  bool is_won = false;
  string X = A, Y = B;
  if (i >= 0) {
    if (X[i] == '?' && Y[i] == '?') {
      X[i] = '1';
      Y[i] = '0';
    } 
    else if (X[i] == '?' && Y[i] != '9') X[i] = char(int(Y[i]) + 1);
    else if (Y[i] == '?' && X[i] != '0') Y[i] = char(int(X[i]) - 1); 
    else return make_pair(LLONG_MAX, make_pair("0", "0"));
  }

  for (size_t j = 0; j < X.size(); j++) {
    if (is_won) { 
      if (X[j] == '?') X[j] = '0';
      if (Y[j] == '?') Y[j] = '9';
    }
    else {
      if (X[j] != '?' && Y[j] != '?') {
        if (X[j] < Y[j]) return {LLONG_MAX,{"0", "0"}};
        if (X[j] > Y[j]) is_won = true;
      }
      else if (X[j] == '?' && Y[j] == '?')  X[j] = Y[j] = '0'; 
      else if (X[j] == '?') X[j] = Y[j]; 
      else if (Y[j] == '?') Y[j] = X[j];
    }
  }

  ll diff = stoll(X) - stoll(Y);
  return make_pair(diff, make_pair(X, Y));
}

pair<ll, pss> b_wins(const string &A, const string &B, int i = -1) {
  auto result = a_wins(B, A, i);
  return make_pair(result.X, make_pair(result.Y.Y, result.Y.X));
}

pair<ll, pss> solve(const string &A, const string &B) {
  auto res = min(a_wins(A, B), b_wins(A, B));
  for (size_t i = 0; i < A.size(); i++) {
    res = min(res, min(a_wins(A, B, i), b_wins(A, B, i)));
  }
  return res;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    string A, B;
    cin >> A >> B;
    cout << "Case #" << t << ": ";
    pair<ll, pss> result = solve(A, B);
    cout << result.Y.X << ' ' << result.Y.Y << '\n';
  }
}
