#include <bits/stdc++.h>
using namespace std;

string s;
int pos;

void skip_whitespace() {
  while (pos < s.size() && isspace(s[pos])) pos++;
}

double read_number() {
  skip_whitespace();
  int start = pos;
  if (pos < s.size() && (s[pos] == '-' || s[pos] == '+')) pos++;
  bool has_dot = false;
  while (pos < s.size() && (isdigit(s[pos]) || s[pos] == '.')) {
    if (s[pos] == '.') {
      if (has_dot) break;
      has_dot = true;
    }
    pos++;
  }
  string num_str = s.substr(start, pos - start);
  double num = stod(num_str);
  return num;
}

double parse() {
  skip_whitespace();
  if (pos < s.size() && s[pos] == '(') {
    pos++;
    skip_whitespace();
    double p = read_number();
    skip_whitespace();
    double e1 = parse();
    skip_whitespace();
    double e2 = parse();
    skip_whitespace();
    if (pos < s.size() && s[pos] == ')') {
      pos++;
    }
    double expected_value = p * (e1 + e2) + (1 - p) * (e1 - e2);
    return expected_value;
  }
  else {
    double num = read_number();
    return num;
  }
}

void solve() {
  while (getline(cin, s)) {
    if (s == "()") break;
    pos = 0;
    double expected_value = parse();
    cout << fixed << setprecision(2) << expected_value << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
