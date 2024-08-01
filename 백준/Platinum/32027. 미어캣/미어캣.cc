#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<int> L, R;
vector<pii> pos;

void input() {
  cin >> N;
  pos.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> pos[i].X;
    char x; cin >> x;
    if(x == 'L') {
      L.push_back(pos[i].X);
      pos[i].Y = 0;
    }
    else {
      R.push_back(pos[i].X);
      pos[i].Y = 1;
    }
  }
}

void solve() {
  if(L.size() == 0 || R.size() == 0) {
    cout << N << '\n';
    return;
  }

  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  int result = 0;
  for(int i = -1; i < N; i++) { // 기준
    vector<int> cur(N);
    int l = L.size() - 1, r = R.size() - 1;

    // 기준에 대해서 왼쪽에 가장 큰 L, 오른쪽에 큰 R 두기
    for(int j = i; j >= 0; j--) {
      if(pos[j].Y == 0) cur[j] = L[l--];
    }
    for(int j = i + 1; j < N; j++) {
      if(pos[j].Y == 1) cur[j] = R[r--];
    }
    for(int j = i; j >= 0; j--) {
      if(pos[j].Y == 1) cur[j] = R[r--];
    }
      for(int j = i + 1; j < N; j++) {
      if(pos[j].Y == 0) cur[j] = L[l--];
    }

    // 이때 볼수있는 미어캣 수 구하기
    int ans = 0;
    vector<int> maxL(N), maxR(N);
    maxR[N - 1] = cur[N - 1];
    for(int j = N - 2; j >= 0; j--) {
      maxR[j] = max(maxR[j + 1], cur[j]);
    }
    maxL[0] = cur[0];
    for(int j = 1; j < N; j++) {
      maxL[j] = max(maxL[j - 1], cur[j]);
    }

    for(int j = 0; j < N; j++) {
      if(pos[j].Y == 0 && (j == 0 || cur[j] > maxL[j - 1]))
        ans++;
      if(pos[j].Y == 1 && (j == N - 1 || cur[j] > maxR[j + 1]))
        ans++;
    }
    result = max(result, ans);
  }
  cout << result << '\n';
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
