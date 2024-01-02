#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, a;
vector<int> v;

int main() {
  // freopen("input.txt", "r", stdin);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;

    if (v.empty() || v.back() < a) {
      v.push_back(a);
    } else {
      auto iterator = lower_bound(v.begin(), v.end(), a);
      *iterator = a;
    }
  }
  cout << v.size();

  return 0;
}