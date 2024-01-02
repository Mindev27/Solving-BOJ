#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int n, m;

// 벡터를 업데이트하는 함수
void update(int idx, ll val, vector<ll> &v) {
  while (idx <= n) {
    v[idx] += val;
    idx += (idx & -idx);
  }
}

// 구간합을 구하는 함수
ll prefixSum(int idx, vector<ll> &v) {
  ll result = 0;
  while (idx >= 1) {
    result += v[idx];
    idx -= (idx & -idx);
  }
  return result;
}

// 구간합을 구하는 함수
ll findAnswer(int start, int end, vector<ll> &v) {
  return prefixSum(end, v) - prefixSum(start - 1, v);
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
    
  cin >> n >> m;
  vector<ll> arr(n + 1);  // 원래 값을 저장
  vector<ll> tree(n + 1); // 펜윅트리 저장

  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {                  // 변경하는 경우
      update(b, c - arr[b], tree); // 바뀐값만큼 업데이트
      arr[b] = c; // 원래 배열도 업데이트
    } else { // 구간합을 구하는 경우
      if(b > c)
        cout << findAnswer(c, b, tree) << "\n";
      else
        cout << findAnswer(b, c, tree) << "\n";
    }
  }
}
