#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 55;
int N;
vector<int> tree[SIZE] = {};

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    if(a == -1) continue;
    tree[a].push_back(i);
  }
}

int solve(int employ) {
  vector<int> temp;
  for(int i = 0; i < tree[employ].size(); i++) {
    int next = tree[employ][i];
    temp.push_back(solve(next));
  }

  sort(temp.begin(), temp.end());

  int result = 0;
  int size = temp.size() - 1;
  for(int i = 0; i < temp.size(); i++) {
    result = max(result, temp[i] + size--);
  }
  result++;
  
  return result;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  cout << solve(0) - 1;

  return 0;
}
