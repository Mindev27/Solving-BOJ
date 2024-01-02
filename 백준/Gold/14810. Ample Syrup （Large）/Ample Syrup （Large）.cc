#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
}
int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    long long int radius, sideArea, sumSide = 0, maxArea;

    //k까지의 옆면의 합 계산(우선순위 큐 사용)
    priority_queue<long long int, vector<long long int>, greater<long long int>> q;
    for(int i = 0; i < k; i++){
      radius = v[i].first;
      sideArea = radius * 2 * v[i].second;
      q.push(sideArea);
      sumSide += sideArea;
    }

    //가장 긴 반지름일때 원 넓이 + 옆면 넓이
    maxArea = radius * radius + sumSide;

    //남은 것들을 순회하면서 가져갈때 더 크다면 가져가기
    for(int i = k; i < n; i++){
      radius = v[i].first;
      sideArea = radius * 2 * v[i].second;

      sumSide += sideArea;
      sumSide -= q.top();
      

      q.pop();
      q.push(sideArea);

      maxArea = max(maxArea, radius * radius + sumSide);
    }
    
    cout<<fixed;
    cout.precision(9);
    cout << "Case #" << t << ": " << maxArea * M_PI << "\n";
  }
}
