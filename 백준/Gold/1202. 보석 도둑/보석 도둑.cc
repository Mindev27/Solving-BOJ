#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

int N, K;
vector<pair<int, int>> jewelry;
vector<int> bagCapacity;
priority_queue<int, vector<int>, less<int>> pq;

void input() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    jewelry.push_back({a, b});
  }
  for(int i = 0; i < K; i++) {
    int a; cin >> a;
    bagCapacity.push_back(a);
  }
}

void solve() {
  sort(bagCapacity.begin(), bagCapacity.end());
  sort(jewelry.begin(), jewelry.end());

  ll result = 0;
  int index = 0;
  for(int i = 0; i < K; i++){
    while(index < N && jewelry[index].first <= bagCapacity[i]){
      pq.push(jewelry[index].second);
      index++;
    }

    if(!pq.empty()){
      result += pq.top();
      pq.pop();
    }
  }

  cout << result;
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
