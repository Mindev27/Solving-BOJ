#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const ll INF = 1e10;
int N, M;
ll road[100005];
ll cnt[100005];
vector<pii> query;

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++)
    cin >> road[i];

  for(int i = 1; i <= M; i++){
    int a, b; cin >> a >> b;
    query.push_back({a, b});
  }
}

void solve() {
  road[0] = -1;
  road[N + 1] = INF;

  // cnt[i] => i번째까지 오르막길의 개수
  cnt[1] = 1;
  for(int i = 2; i <= N; i++){
    if(road[i - 1] < road[i])
      cnt[i] = cnt[i - 1];
    else
      cnt[i] = cnt[i - 1] + 1;
  }

  for(int i = 0; i < M; i++) {
    int s = query[i].X;
    int e = query[i].Y;

    int downNum = cnt[e] - cnt[s]; // 내리막길 개수
    int upNum = e - s - downNum; // 오르막길 개수

    // 뒤집으면 오르막길과 내리막길이 바뀐다
    int change = upNum - downNum;

    // 시작과 끝 처리
    // 시작점에서 바뀐경우
    if((road[s - 1] < road[s]) != (road[s - 1] < road[e])) {
      if(road[s - 1] < road[s]) // 되다가 안되는 경우
        change++;
      else                      // 안되다가 되는 경우
        change--;
    }

    // 끝점에서 바뀐 경우
    if((road[e] < road[e + 1]) != (road[s] < road[e + 1])) {
      if(road[e] < road[e + 1]) // 되다가 안되는 경우
        change++;
      else                      // 안되다가 되는 경우
        change--;
    }

    cout << cnt[N] + change << "\n";
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