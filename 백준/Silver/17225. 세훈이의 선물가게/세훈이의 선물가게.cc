#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int bTime, rTime, giftNum;
vector<pair<int, int>> v; // 포장한 시간과 색깔 저장 0:B, 1:R

void input() {
  cin >> bTime >> rTime >> giftNum;

  int bCurTime = 0;
  int rCurTime = 0;

  for (int i = 0; i < giftNum; i++) {
    int a, c;
    char b;
    cin >> a >> b >> c;

    if (b == 'B') { // 상만이인 경우
      a = bCurTime > a ? bCurTime : a; // 앞 포장이 안끝났으면 끝나는 시간에 시작
      for (int j = 0; j < c; j++) {
        v.push_back({a + j * bTime, 0}); // 포장시간과 색 저장
        bCurTime = a + (j + 1) * bTime;
      }
    } 
    else { // 지수인 경우
      a = rCurTime > a ? rCurTime : a; // 앞 포장이 안끝났으면 끝나는 시간에 시작
      for (int j = 0; j < c; j++) {
        v.push_back({a + j * rTime, 1}); // 포장시간과 색 저장
        rCurTime = a + (j + 1) * rTime;
      }
    }
  }
}

void printAnswer() {
  sort(v.begin(), v.end()); // 0:B, 1:R라 항상 B가 앞에옴
  
  vector<int> bGift, rGift;
  int packNum = 1; // 포장한 선물의 순서
  
  // 선물정보를 돌며 누구의 것인지 따로 저장
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second == 0)
      bGift.push_back(packNum);
    else
      rGift.push_back(packNum);

    packNum++;
  }

  // 상민이의 포장개수 출력
  cout << bGift.size() << "\n";
  for (int i = 0; i < bGift.size(); i++) {
    cout << bGift[i] << ' ';
  }
  cout << "\n";

  // 지수의 포장개수 출력
  cout << rGift.size() << "\n";
  for (int i = 0; i < rGift.size(); i++) {
    cout << rGift[i] << ' ';
  }
  cout << "\n";
}

int main(void) {
  // freopen("input.txt", "r", stdin);

  input();

  printAnswer();

  return 0;
}