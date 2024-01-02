#include <iostream>
#include <vector>

using namespace std;

void solve(int a, int b, int s) {
  bool isPossible = false;
  // m1 > m2로 만들기
  int m1 = a > b ? a : b;
  int m2 = a < b ? a : b;

  vector<bool> v(m2); // m1크기의 bool 배열 만들기
  int boolNum = 0; // 모든 나머지가 안될때까지 탐색함 나머지를 확인한 개수
  
  int cycle = s / m1; // 큰 돈을 최대 가져갈수 있는 횟수

  for (int i = cycle; i >= 0; i--) {
    int leftS = s - m1 * i; // 큰 돈 빼고 남은 금액

    if (leftS % m2 == 0 && !isPossible) { // 남은 금액 처리되고 이전에 가능하지 않았다면
      isPossible = true;
      if (a > b)
        cout << i << ' ' << leftS / m2 << "\n";
      else
        cout << leftS / m2 << ' ' << i << "\n";
      break;
    }
    else{ // 처리가 안됐다면
      if(!v[leftS % m2]) v[leftS % m2] = true;
      boolNum++;
    }

    if(boolNum == m2){ // 다 확인했다면 불가
      cout << "Impossible\n";
      return;
    }
  }

  if (!isPossible) {
    cout << "Impossible\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int T;
  cin >> T;
  while (T--) {
    int a, b, s;
    cin >> a >> b >> s;

    solve(a, b, s);
  }
}
