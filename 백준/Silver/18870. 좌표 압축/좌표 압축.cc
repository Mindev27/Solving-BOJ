#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  int index, data[1000001] = {};
  vector<int> v;
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> data[i];
    v.push_back(data[i]);
  }

  sort(v.begin(), v.end());

  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 0; i < n; i++){
    index = lower_bound(v.begin(), v.end(), data[i]) - v.begin();
    cout << index << ' ';
  }
}