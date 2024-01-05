#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int N;
ll joy = 0;
vector<pair<int, int>> goodBook; // 읽으면 결국 좋은 책(먼저 읽기)
vector<pair<int, int>> badBook; // 읽으면 결국 손해인 책(나중에 읽기)

void input() {
  cin >> N;
  for(int i = 0; i < N; ++i){
    int a, b; cin >> a >> b;
    if(a <= b) goodBook.push_back({a, b});
    else badBook.push_back({a, b});
  }
}

// 잃는게 적은순으로 정렬
bool goodCompare(pair<int, int> &a, pair<int, int> &b) {
  return a.first < b.first;
}

// 잃는게 많은 순으로 정렬
bool badCompare(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

bool canRead() {
  sort(goodBook.begin(), goodBook.end(), goodCompare);
  
  // 이득인 책을 먼저읽기
  for(int i = 0; i < goodBook.size(); ++i) {
    joy -= goodBook[i].first;
    if(joy < 0) return false;
    joy += goodBook[i].second;
  }

  sort(badBook.begin(), badBook.end(), badCompare);
  
  // 손해인 책을 읽기
  for(int i = 0; i < badBook.size(); ++i) {
    joy -= badBook[i].first;
    if(joy < 0) return false;
    joy += badBook[i].second;
  }

  return true;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  if(canRead()) cout << 1;
  else cout << 0;

  return 0;
}
