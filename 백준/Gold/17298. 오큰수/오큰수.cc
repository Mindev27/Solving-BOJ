#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N;
int arr[1000005];
stack<int> s;


void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
} 

void solve() {
  for(int i = N; i >= 1; i--) {
    if(s.empty()){
      s.push(arr[i]);
      arr[i] = -1;
    }

    else if(!s.empty() && s.top() > arr[i]) {
      int cur = s.top();
      s.push(arr[i]);
      arr[i] = cur;
    }
    else {
      while(!s.empty() && s.top() <= arr[i]) s.pop();
      if(s.empty()) {
        s.push(arr[i]);
        arr[i] = -1;
      }
      else {
        int cur = s.top();
        s.push(arr[i]);
        arr[i] = cur;
      }
    }
  }
  for(int i = 1; i <= N; i++)
    cout << arr[i] << ' ';
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
