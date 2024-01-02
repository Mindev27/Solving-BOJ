#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<bool> v[55]; // v[i]의 친구 정보
vector<bool> copyV[55];

void input() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    v[i].resize(n + 1);
    copyV[i].resize(n + 1);
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a][b] = true;
    v[b][a] = true;
    copyV[a][b] = true;
    copyV[b][a] = true;
  }
}

bool isAllFriend() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j && !v[i][j])
        return false;
    }
  }
  return true;
}

void addFriend(int me) {
  bool added[55] = {};

  for (int i = 1; i <= n; i++) {
    if (!v[me][i] || me == i)
      continue;
    int myFriend = i;

    for (int j = 1; j <= n; j++) {
      if (!v[myFriend][j] || myFriend == j || v[me][j] || me == j || added[j])
        continue;
      int nextFriend = j;

      copyV[me][nextFriend] = true;
      copyV[nextFriend][me] = true;
      added[nextFriend] = true;
      cnt++;
    }
  }
}

void copyBoard() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      v[i][j] = copyV[i][j];
    }
  }
}

void solve() {
  int days = 0;
  vector<int> ans;

  while (true) {
    copyBoard();
    
    if (isAllFriend())
      break;

    cnt = 0; // 늘어난 친구의 수

    for (int i = 1; i <= n; i++) { // 각각 친구 추가
      addFriend(i);
    }

    days++;
    ans.push_back(cnt / 2);
  }

  cout << days << '\n';
  for (int i : ans)
    cout << i << '\n';
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