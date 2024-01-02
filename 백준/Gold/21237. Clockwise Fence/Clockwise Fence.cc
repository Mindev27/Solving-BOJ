#include <iostream>

using namespace std;

string cwTurn[4] = {"NE", "ES", "SW", "WN"};
string ccwTurn[4] = {"NW", "WS", "SE", "EN"};

// CW인지 확인하는 함수
bool isCw(string path) {
  int cnt = 0;
  for(int i = 0; i < path.size() - 1; i++){
    if(path[i] == path[i + 1]) continue; // 직진이면 확인X

    // 시계방향인지 반시계방향 회전인지 확인
    string temp = "";
    temp += path[i]; temp += path[i + 1];
    bool checkCW = false;
    for(int i = 0; i < 4; i++){
      if(temp == cwTurn[i]) checkCW = true;
    }

    // 시계방향이면 +1 아니라면 -1
    if(checkCW) cnt++;
    else cnt--;

  }

  // 마지막도 처리해주기
  string lastStr = "";
  lastStr += path[path.size() - 1]; lastStr += path[0];
  for(int i = 0; i < 4; i++)
    if(lastStr == cwTurn[i]) cnt++;
  for(int i = 0; i < 4; i++)
    if(lastStr == ccwTurn[i]) cnt--;

  if(cnt == 4) return true;
  else return false;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while(T--){
    string path; cin >> path;
    if(isCw(path)) cout << "CW\n";
    else cout << "CCW\n";
  }

  return 0;
}
