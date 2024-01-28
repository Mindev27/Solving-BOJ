#include <algorithm>

#include <cmath>

#include <iostream>

#include <vector>

#include <deque>

#define ll long long

#define X first

#define Y second

#define pii pair<int, int>

using namespace std;

int N;

vector<int> query;

deque<int> ans;

void input() {

  cin >> N;

  for(int i = 0; i < N; i++) {

    int x;

    cin >> x;

    query.push_back(x);

  }

}

void solve() {

  int num = 1;

  reverse(query.begin(), query.end());

  for(int i : query) {

    if(i == 1)

      ans.push_back(num++);

    else if(i == 2){

      int temp = ans.back();

      ans.pop_back();

      ans.push_back(num++);

      ans.push_back(temp);

    }

    else

      ans.push_front(num++);

  }

  while(!ans.empty()){

    cout << ans.back() << ' ';

    ans.pop_back();

  }

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