#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
#include <sstream>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

struct Item {
  bool isOper; // 연산자인지 식인지
  int a, b; // ax + b
  char oper;
  Item() : Item(0, 0) {}
  Item(char op1) : isOper(1), oper(op1) {}
  Item(int a1, int b1) : isOper(0), a(a1), b(b1) {}
  Item operator +(Item it)const{ return Item(a+it.a, b+it.b); }
  Item operator -(Item it)const{ return Item(a-it.a, b-it.b); }
  Item operator *(Item it)const{ return Item(it.a == 0 ? a*it.b : it.a*b, b*it.b); }
};
string s;

string solve() {
  Item E[2]; // 좌변우변
  for(int j = 0, i = 0; j < 2; i++, j++) { // 좌변식 정리 우변식 정리
    vector<Item> P;
    stack<char> S;
    for(; s[i] != '=' && i < s.size(); i++) {
      if(isdigit(s[i])) { // 숫자라면
        int val = s[i] - '0';
        while(isdigit(s[i + 1])) {
          i++;
          val = val * 10 + s[i] - '0';
        }
        P.push_back(Item(0, val));
      }
      else if(s[i] == 'x') {
        P.push_back(Item(1, 0));
      }
      else if(s[i] == '(') S.push('(');
      else if(s[i] == ')') {
        while(S.top() != '(') {
          P.push_back(S.top());
          S.pop();
        }
        S.pop();
      }
      else if(s[i] == '*') S.push('*');
      else if(s[i] == '+') {
        while(!S.empty() && (S.top() == '-' || S.top() == '*')) {
          P.push_back(S.top());
          S.pop();
        }
        S.push('+');
      }
      else if(s[i] == '-') {
        while(!S.empty() && (S.top() == '-' || S.top() == '*')) {
          P.push_back(S.top());
          S.pop();
        }
        S.push('-');
      }
      
    }
    while(!S.empty()) {
      P.push_back(S.top());
      S.pop();
    }

    // 모든 요소를 연산해서 하나로 만들기
    stack<Item> SS;
    for(int i = 0; i < P.size(); i++) {
      if(!P[i].isOper) SS.push(P[i]);
      else {
        Item it1 = SS.top(); SS.pop();
        Item it2 = SS.top(); SS.pop();
        if(P[i].oper == '*') SS.push(it1 * it2);
        else if(P[i].oper == '+') SS.push(it1 + it2);
        else SS.push(it1 - it2);
      }
    }

    E[j] = SS.top();
  }

  string ans = "";
  Item result = E[0] - E[1];
  if(result.a == 0) {
    if(result.b == 0) return "Infinitely many solutions.";
    else return "No solution.";
  }
  else {
    ans += "x = ";
    double xVal = -1.0 * (double)result.b / result.a;
    ostringstream oss;
    oss << fixed << setprecision(6) << xVal;

    ans += oss.str();
    return ans;
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 0;
  while(cin >> s) {
    cout << "Equation #" << ++t << "\n" << solve() << "\n\n";
  }

  return 0;
}
