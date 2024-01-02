/*
  R : 한 칸 오른쪽으로         3
  L : 한 칸 왼쪽으로           4
  B : 한 칸 아래로             6
  T : 한 칸 위로               1
  RT : 오른쪽 위 대각선으로     2
  LT : 왼쪽 위 대각선으로       0
  RB : 오른쪽 아래 대각선으로   7
  LB : 왼쪽 아래 대각선으로     5
*/

#include <iostream>
#include <vector>

using namespace std;

int board[10][10] = {};
pair<int, int> king;
pair<int, int> rock;
int moveNum;
vector<int> moves;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

// 입력
void input() {
  string kingStart, rockStart;
  cin >> kingStart >> rockStart;
  
  king.first = 7 - (kingStart[1] - '1');
  king.second = kingStart[0] - 'A';
  
  rock.first = 7 - (rockStart[1] - '1');
  rock.second = rockStart[0] - 'A';

  cin >> moveNum;
  for(int i = 0; i < moveNum; i++){ // 움직이는 방향인 dx dy의 인덱스를 저장
    string move; cin >> move;
    if(move == "R") moves.push_back(3);
    if(move == "L") moves.push_back(4);
    if(move == "B") moves.push_back(6);
    if(move == "T") moves.push_back(1);
    if(move == "RT") moves.push_back(2);
    if(move == "LT") moves.push_back(0);
    if(move == "RB") moves.push_back(7);
    if(move == "LB") moves.push_back(5);
  }
}

void solve() {
  for(int i : moves){ // moves를 순회하며 시뮬레이션 구현
    int nKingX = king.first + dx[i];
    int nKingY = king.second + dy[i];

    // 범위 벗어남
    if(nKingX < 0 || nKingX >= 8 || nKingY < 0 || nKingY >= 8)
      continue;

    // 다음칸이 돌이라면
    if(nKingX == rock.first && nKingY == rock.second){
      int nRockX = rock.first + dx[i];
      int nRockY = rock.second + dy[i];

      // 돌 다음칸이 벽인 경우
      if(nRockX < 0 || nRockX >= 8 || nRockY < 0 || nRockY >= 8)
        continue;

      // 돌을 밀수있는 경우 이동
      king = {nKingX, nKingY};
      rock = {nRockX, nRockY};
    }

    else king = {nKingX, nKingY}; // 다음칸이 빈공간이면 이동
  }

  // 두 위치 출력
  cout << (char)(king.second + 'A') << 8 - king.first << '\n';
  cout << (char)(rock.second + 'A') << 8 - rock.first;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}