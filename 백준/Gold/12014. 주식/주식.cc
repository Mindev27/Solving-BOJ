#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> &prices) {
  vector<int> lis;
  for (int price : prices) {
    auto it = lower_bound(lis.begin(), lis.end(), price);
    if (it == lis.end())
      lis.push_back(price);
    else
      *it = price;
  }
  return lis.size();
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, K;
    cin >> N >> K;
    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
      cin >> prices[i];
    }

    int lisLength = LIS(prices);
    cout << "Case #" << t << "\n";
    cout << (lisLength >= K ? 1 : 0) << "\n";
  }
  return 0;
}
