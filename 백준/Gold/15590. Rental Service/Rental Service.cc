#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

ll N, M, R, totalMilk;
vector<ll> cow;
vector<pll> shop;
vector<ll> neighbor;
vector<ll> wantMilk;
void input() {
  cin >> N >> M >> R;
  cow.resize(N);
  shop.resize(M);
  wantMilk.resize(M);
  neighbor.resize(R);

  for(int i = 0; i < N; i++){
    cin >> cow[i];
    totalMilk += cow[i];
  }
  for(int i = 0; i < M; i++){
    cin >> shop[i].X >> shop[i].Y;
  }
    for(int i = 0; i < R; i++)
    cin >> neighbor[i];
}

bool comp(const pll &a, const pll &b) {
  return a.first < b.first;
}

void solve() {
  sort(cow.begin(), cow.end()); // 우유 생산량이 적은것 순으로 정렬
  sort(shop.begin(), shop.end(), [](pll a, pll b) { 
    return a.Y > b.Y;
  }); // 우유 가격을 높은순으로
  sort(neighbor.begin(), neighbor.end(), [](ll a, ll b) {
    return a > b;
  }); // 비싸게 사려는 사람순 정렬

  for(int i = 0; i < M; i++){
    wantMilk[i] = shop[i].Y;
  }

  // 가게와 이웃에 대해 누적합으로 바꾸기
  for(int i = 0; i < M; i++)
    shop[i].Y = shop[i].X * shop[i].Y;
  for(int i = 1; i < M; i++) {
    shop[i].X += shop[i - 1].X;
    shop[i].Y += shop[i - 1].Y;
  }

  for(int i = 1; i < R; i++)
    neighbor[i] += neighbor[i - 1];

  // i마리를 팔때 얻는 이득 계산
  ll answer = 0;
  ll rentCost = 0;
  for(int i = 0; i < N; i++) {
    ll curProfit = 0;
    int curIndex = lower_bound(shop.begin(), shop.end(), pii(totalMilk, LLONG_MAX), comp) - shop.begin();

    if(curIndex == M) curProfit = shop[M - 1].Y;
    else if(curIndex != 0) {
      curProfit = shop[curIndex - 1].Y;
      ll left = totalMilk - shop[curIndex - 1].X;
      curProfit += wantMilk[curIndex] * left; // 남은 우유만큼 사기
    }
    else{
      ll left = totalMilk;
      curProfit += wantMilk[curIndex] * left;
    }
    answer = max(answer, rentCost + curProfit);
    if(i < R) rentCost += i == 0 ? neighbor[i] : neighbor[i] - neighbor[i - 1];
    totalMilk -= cow[i];
  }
  answer = max(answer, rentCost);
  cout << answer;
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
