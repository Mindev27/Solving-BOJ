#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <set>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, K;
string word[55];
int A[55]; // 각 단어에 존재하는 글자 정보
int result;

void input() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> word[i];
  }
}

// 사용한 단어의 개수, 현재 값, 확인한 알파벳 인덱스
void backTracking(int used, int cur, int idx) {
  if(used == K) {
    int canRead = 0;
    for(int i = 0 ; i < N; i++) {
      if((cur | A[i]) == cur) canRead++;
    }
    result = max(result, canRead);
    return;
  }

  for(int i = idx; i < 26; i++) {
    int x = (1 << i); // i번째 단어
    if((cur | x) == cur) continue; // 가지고 있으면 패스
    backTracking(used + 1, cur | x, i + 1);
  }
}

void solve() {
  if(K < 5) { cout << 0; return; } // 예외처리

  // 각 단어의 정보를 비트마스킹을 이용해 정수값으로 치환
  for(int i = 0; i < N; i++) {
    int cur = 0;
    for(char c : word[i]) {
      cur |= (1 << (c - 'a'));
    }
    A[i] = cur;
  }

  // a, n, t, i, c을 미리 가지고 시작
  int start = 1;
  start |= (1 << ('n'-'a'));
  start |= (1 << ('t'-'a'));
  start |= (1 << ('i'-'a'));
  start |= (1 << ('c'-'a'));
  
  result = 0;
  backTracking(5, start, 0);

  cout << result;
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
