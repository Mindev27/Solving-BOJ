#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>

using namespace std;

const int SIZE = 100005;
int N, changeToOne = 0, changeToTwo = 0;
vector<pii> rookPos;
vector<int> row[SIZE];
vector<int> col[SIZE];
int color[200005] = {};


void input() {
  cin >> N;
  rookPos.push_back({0, 0}); // 인덱스 맞춰주기
  
  // 1번 체스판룩 1~N, 2번 체스판룩 N+1~2N
  for(int i = 1; i <= 2 * N; i++) {
    int x, y; cin >> x >> y;
    rookPos.push_back({x, y});
    row[x].push_back(i);
    col[y].push_back(i);
  }
}

int paintColor(int x) {
  queue<int> q;
  int change = 0; // 바뀌는 개수
  int NodeNum = 0;
  
  //처음 노드 칠하기
  color[x] = 1;
  q.push(x);

  while(!q.empty()){
    int curNode = q.front();
    int curColor = color[curNode];
    q.pop();

    NodeNum++;
    
    if(curNode <= N && curColor == 2) change++;
    else if(curNode > N && curColor == 1) change++;
    
    int curX = rookPos[curNode].X;
    int curY = rookPos[curNode].Y;
    
    //연결된 노드 탐색
    for(int next : row[curX]){ // 가로
      if(next == curNode) continue;
      
      if(color[next] == 0) {
        if(curColor == 1) color[next] = 2;
        else color[next] = 1;
        q.push(next);
      }
    }

    for(int next : col[curY]){ // 세로
      if(next == curNode) continue;

      if(color[next] == 0) {
        if(curColor == 1) color[next] = 2;
        else color[next] = 1;
        q.push(next);
      }
    }
  }

  return min(change, NodeNum - change);
}

void solve() {
  // 가로나 세로에 2개씩만 있어야 함
  for(int i = 1; i <= N; i++){
    if(row[i].size() != 2 || col[i].size() != 2) {
      cout << "-1";
      return;
    }
  }

  // 이분 그래프 만들어보기
  int result = 0;
  memset(color, 0, sizeof(color));
  for(int i = 1; i <= 2 * N; i++) {
    if(color[i] == 0) {
      result += paintColor(i);
    }
  }
  
  cout << result / 2;
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
