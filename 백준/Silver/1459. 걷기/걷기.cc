#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int finishX, finishY;
int walk, slide;

void solve() {
  // 대각선이 이득인지 나타내는 변수
  bool goSlide = walk * 2 > slide;
  ll result = 0;

  ll maxNum = max(finishX, finishY);
  ll minNum = min(finishX, finishY);
  
  if(goSlide){ // 대각선을 이용하는게 이득

    if(walk * 2 > slide * 2){ // 한칸씩 이동하는게 손해라면
      // x, y 좌표의 차가 2 이상이면 대각선으로 2칸 움직인 효과를 낼 수 있다
      // 최대 좌표와 최소 좌표가 2차이나면 없앨수있음 즉 둘의 차가 2의 배수면
      // 대각선이동만으로 도착할 수 있다
      if((maxNum - minNum) % 2 == 0)
        result = maxNum * slide;
      else
        result = (maxNum - 1) * slide + walk;
    }

    else{ // 한칸씩 두번 이동하는게 대각선 두번보다 낫다면
      result = minNum * slide;
      result += (maxNum - minNum) * walk;
    } 
  }
  else{ // 그냥 가는게 더 빠름
    result = (maxNum + minNum) * walk;
  }

  cout << result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> finishX >> finishY >> walk >> slide;

  solve();

  return 0;
}