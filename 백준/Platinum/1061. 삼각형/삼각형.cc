#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, M;
vector<pii> R, G, B;    // R, G, B의 각 좌표
vector<pii> cR, cG, cB; // convex hull을 구성하는 점
int bestR[300][300];    // G=G[i], B=B[j]일때 최대 넓이
int bestG[300][300];    // B=B[i], R=R[j]일때 최대 넓이
int bestB[300][300];    // R=R[i], G=G[j]일때 최대 넓이

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    string temp; cin >> temp;
    for(int j = 1; j <= M; j++) {
      switch (temp[j - 1]){
        case 'R': R.push_back({i, j}); break;
        case 'G': G.push_back({i, j}); break;
        case 'B': B.push_back({i, j}); break;
      }
    }
  }
}

// 양수:CCW, 음수:CW, 0:평행
int ccw(pii &a, pii &b, pii &c) {
  int val = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
  return val;
}

// convex hull위의 점도 포함해야하므로 등호없이 monoton chain
vector<pii> makeConvexHull(vector<pii> &v) {
  sort(v.begin(), v.end());
  int safe = 1;
  vector<pii> hull;
  for(auto &cur : v){
    while(hull.size() > safe && ccw(hull[hull.size()-2], hull.back(), cur) > 0)
      hull.pop_back();
    hull.push_back(cur);
  }
  if(hull.size() == v.size()) return hull;
  hull.pop_back();
  safe = hull.size();
  
  reverse(v.begin(), v.end());
  for(auto &cur : v){
    while(hull.size() > safe && ccw(hull[hull.size()-2], hull.back(), cur) > 0)
      hull.pop_back();
    hull.push_back(cur);
  }
  
  hull.pop_back();
  return hull;
}

// a, b, c를 이루는 삼각형 넓이의 2배 계산
int calcArea(pii &a, pii &b, pii &c) {
  int result = a.X * b.Y + b.X * c.Y + c.X*a.Y;
  result -= a.Y * b.X + b.Y * c.X + c.Y * a.X;
  return abs(result);
}

void solve() {
  // RGB에 대해 convex hull 구성
  cR = makeConvexHull(R);
  cG = makeConvexHull(G);
  cB = makeConvexHull(B);

  // 두 점이 고정일때 최대넓이 계산
  for(int i = 0; i < cR.size(); i++) {
    for(int j = 0; j < cG.size(); j++) {
      for(int k = 0; k < cB.size(); k++) {
        int curArea = calcArea(cR[i], cG[j], cB[k]);
        bestR[j][k] = max(bestR[j][k], curArea);
        bestG[k][i] = max(bestG[k][i], curArea);
        bestB[i][j] = max(bestB[i][j], curArea);
      }
    }
  }

  // 최대크기의 아름다운 삼각형 개수 계산
  int pretty = 0;
  for(int i = 0; i < cR.size(); i++) {
    for(int j = 0; j < cG.size(); j++) {
      for(int k = 0; k < cB.size(); k++) {
        int curArea = calcArea(cR[i], cG[j], cB[k]);
        if(curArea == bestR[j][k] && curArea == bestG[k][i] && curArea == bestB[i][j])
          pretty++;
      }
    }
  }

  // 모든 삼각형의 개수 - 아름다운 삼각형 = 커질 수 있는 아름다운 삼각형
  int answer = R.size() * G.size() * B.size() - pretty;
  cout << answer;
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