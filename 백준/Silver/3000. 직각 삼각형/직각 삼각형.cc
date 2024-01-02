#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
vector<pair<int, int>> v; // 점 좌표정보 저장
int xPointNum[MAX] = {}; // x축 위에 있는 점 개수
int yPointNum[MAX] = {}; // y축 위에 있는 점 개수

void input(){
  int pointNum;
  cin >> pointNum;

  for(int i = 0; i < pointNum; i++){
    int a, b; 
    cin >> a >> b;

    v.push_back({a, b});
    xPointNum[a]++;
    yPointNum[b]++;
  }
}

long long int solve() {
  long long int result = 0;

  for(auto point : v){
    int x = point.first;
    int y = point.second;
    
    long long int temp = 1;
    temp *= xPointNum[x] - 1;
    temp *= yPointNum[y] - 1;
    
    result += temp;
  }
  
  return result;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();

  cout << solve();
}