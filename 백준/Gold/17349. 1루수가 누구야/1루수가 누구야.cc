#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

vector<pii> v;
int one[10];
vector<int> answer;

void input() {
  for (int i = 1; i <= 9; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
}

void solve() {
  for (int lie = 0; lie < 9; lie++) {
    memset(one, 0, sizeof(one));

    if (v[lie].X == 1) one[v[lie].Y] = 1;
    if (v[lie].X == 0) one[v[lie].Y] = -1;

    
    for (int j = 0; j < 9; j++) {
      if (lie == j) continue;
      
      if (v[lie].X == v[j].X && v[lie].Y == v[j].Y) {
        for (int l = 1; l <= 9; l++) {
          one[l] = 1;
        }
        break;
      }
      
      if (v[j].X == 0) one[v[j].Y] = 1;
      if (v[j].X == 1) one[v[j].Y] = -1;
    }
    int num, can = 0;
    for (int j = 1; j <= 9; j++) {
      if (one[j] == -1) {
        can++;
        num = j;
      }
    }
    if (can == 1) {
      answer.push_back(num);
    }
    if (can < 1) {
      for (int j = 1; j <= 9; j++) {
        if (one[j] == 0) {
            answer.push_back(j);
        }
      }
    }
  }
  if (answer.size() == 1)
    cout << answer[0] << "\n";
  else cout << -1 << "\n";
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
