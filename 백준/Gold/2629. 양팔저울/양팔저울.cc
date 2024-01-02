#include <iostream>

using namespace std;

// dp[x][y] : x번째까지 담았을때 y무게를 담을수 있는지 여부
bool dp[31][15001] = {};
int weight[31] = {};
int questions[10] = {};
int n, questionNum;

void input(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> weight[i];

  cin >> questionNum;
  for(int i = 0; i < questionNum; i++)
    cin >> questions[i];
  
}

void solve(int x, int y) {
  if(x > n || dp[x][y]) // 범위 벗어남, 중복탐색 방지 
    return;
  
  dp[x][y] = true;

  int WeightGap = y - weight[x] > 0 ? y - weight[x] : weight[x] - y;
  solve(x + 1, WeightGap); // 뺼때
  solve(x + 1, y + weight[x]); // 더할때
  solve(x + 1, y); // 안 넣을때
 
}

void printAnswer(){
  for(int i = 0; i < questionNum; i++){
    if(questions[i] > 15000 || !dp[n][questions[i]])
      cout << "N ";
    else
      cout << "Y ";
  }
}

int main() {
  input();

  solve(0, 0);

  printAnswer();
}