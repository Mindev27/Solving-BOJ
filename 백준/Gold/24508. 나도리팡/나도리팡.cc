#include <iostream>
#include <algorithm>

using namespace std;

int nadori[100001] = {};
int n, k, t;
long long int nadoriSum = 0;

void input();
string solve();

void input() {
  cin >> n >> k >> t;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    nadoriSum += a;
    nadori[i] = a;
  }
}

string solve() {
  int startIdx = 0;
  int endIdx = n - 1;

  // 애초에 나도리가 없다면
  if(nadoriSum == 0)
    return "YES";
  
  // 나도리를 모두 터트릴 수 없다면
  if (nadoriSum % k != 0)
    return "NO";

  long long int count = 0; // 총 움직인 횟수
  while (true) {   
    int leftNadori = nadori[startIdx];
    int needNadori = k - nadori[endIdx];

    // 필요한 나도리수가 더 많으면
    if (leftNadori < needNadori) {
      nadori[endIdx] += leftNadori; // 끝으로 옮기고
      startIdx++; // 인덱스 한칸 이동
      count += leftNadori; // 움직인 횟수에 누적
    }

    // 남은 나도리가 더 많으면
    else if (leftNadori > needNadori) {
      nadori[startIdx] -= needNadori; // 사용한 만큼 빼기
      endIdx--; // 인덱스 한칸 이동
      count += needNadori; // 움직인 횟수에 누적
    }

    // 필요한 수와 남은 수가 같다면
    else {
      if (startIdx + 1 == endIdx) { // 바로 붙어있다면
        count += leftNadori; // 다 옮기기
        break;
      }
      else{ // 바로 붙어있지 않다면
        count += leftNadori; // 다 옮기기
        startIdx++;
        endIdx--;
      }
    }
  }

  if(count <= t)
    return "YES";
  else
    return "NO";
}

int main() {

  input();

  sort(nadori, nadori + n);

  cout << solve();
}