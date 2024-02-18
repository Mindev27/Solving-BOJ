#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
int hi[100005];
vector<pii> a;
int parent[100005];
int sz[100005];


void input() {
  for(int i = 0; i < N; i++) {
    cin >> hi[i];
    a.push_back({hi[i], i});
    parent[i] = i;
    sz[i] = 1;
  }
}

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
  }
}

void solve() {
  sort(a.rbegin(), a.rend()); // 높이가 높은 순으로 정렬
  ll answer = 0;

  for(pii &i : a) {
    int height = i.X;
    int index = i.Y;
    // 합칠 수 있는지 확인
    if (index > 0 && hi[index-1] >= height) Union(index, index-1);
    if (index < N-1 && hi[index+1] >= height) Union(index, index+1);
    // 집합의 크기(너비) * 높이로 넓이 계산
    answer = max(answer, (ll)sz[find(index)] * height);
  }

  cout << answer << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while(true) {
    cin >> N;
    if(N == 0) break;
    a.clear();
    input();
    solve();
  }
  

  return 0;
}
